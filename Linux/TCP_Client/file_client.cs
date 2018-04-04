using System;
using System.IO;
using System.Net;
using System.Net.Sockets;

//IKN's bib, benyttes til at finde path og file ved indsættelse via. exe

using System.Text; //Bennyttes til decodning Encoding.ASCII.GetBytes
using System.Diagnostics; //Bruges til stopWatch() funktioner
using System.Threading; //Tid til sekunder

namespace tcp
{
	class file_client
	{
		/// <MINE VARIABLER, HUSK AT SÆTTE MIG>
		string receivedPath = Environment.GetFolderPath( Environment.SpecialFolder.DesktopDirectory ) + "/"; //string receivedPath = "/root/Desktop/Download/";
		const int forBites = 1; //Bit der ligger før modtagelsen i bufferen
		/// <MINE VARIABLER, HUSK AT SÆTTE MIG>

		/// <summary>
		/// The PORT.
		/// </summary>
		const int PORT = 9000;
		/// <summary>
		/// The BUFSIZE.
		/// </summary>
		const int BUFSIZE = 1000;//Må ikke sættes over jombo buffer på lan er den 8960 på wifi er den efter IEEE på 7895. Default uden jumbo er 1460-"70"fra de 4 TCP layer så 1382

		/// <summary>
		/// Initializes a new instance of the <see cref="file_client"/> class.
		/// </summary>
		/// <param name='args'>
		/// The command-line arguments. First ip-adress of the server. Second the filename
		/// </param>



		private file_client (string[] args)
		{
			// TO DO Your own code

			try
			{
				//User indtaster IP
				Console.WriteLine("Client Started");
				Console.WriteLine("\n Write the ip, to server");
				string IP = Console.ReadLine();
				Console.WriteLine("\n Trying to connect to");
				Console.WriteLine(IP);

				//Tjekker clients internet forbindelse opsættning
				IPAddress[] ipAddress = Dns.GetHostAddresses(IP);
				IPEndPoint ipEnd = new IPEndPoint(ipAddress[0], PORT);

				//Opretter en socket
				Socket clientSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp );
				clientSock.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout,10000); //Timeout ved modtagelse
				clientSock.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.SendTimeout,3000); //Timeout ved sendning

				//Connector til server
				clientSock.Connect(ipEnd);
				Console.WriteLine("\n Connection succes"); 

				//Du vælger mappen
				Console.WriteLine("\n Write the path on server, if wrong it will take default path");
				string choice = Console.ReadLine();
				Console.WriteLine("\n you wrote");
				Console.WriteLine(choice);
				byte[] msg1 = Encoding.ASCII.GetBytes (choice); 
				clientSock.Send (msg1);

				//Mulligher for filer i path
				Console.WriteLine("\n Asking server for file...");
				byte[] bytes = new byte[BUFSIZE]; 
				int bytesRec = clientSock.Receive (bytes);  
				Console.WriteLine ("Mullige valg = {0}", Encoding.ASCII.GetString (bytes, 0, bytesRec));

				//Du vælger file
				Console.WriteLine("\n Write the file, to recive from server");
				choice = Console.ReadLine();
				Console.WriteLine("\n you wrote");
				Console.WriteLine(choice);
				byte[] msg2 = Encoding.ASCII.GetBytes (choice); 
				clientSock.Send (msg2);

				//Går igang med at modtage
				receiveFile (clientSock, choice); //Starter modtagelse

				//Giver et resume af overførslen, hvilken file og hvor den er endt
				byte[] fileData = File.ReadAllBytes(receivedPath + choice);
				int count = fileData.Length; //Filens størrelse
				Console.WriteLine("Server:{0} connected & File {1} & size: {2} in bytes", clientSock.RemoteEndPoint, choice, count);
				Console.WriteLine("\n File location: {0}", receivedPath);
				Console.WriteLine("\n Done closing connection");

				//Lukker socket og forbindelse
				clientSock.Close();
			}
			catch //Ved fejl i en opration
			{
				Console.Clear();
				Console.WriteLine("\n ERROR, Restarting...");
			}
			//Lukker ned

		}


		/// <summary>
		/// Receives the file.
		/// </summary>
		/// <param name='fileName'>
		/// File name.
		/// </param>
		/// <param name='io'>
		/// Network stream for reading from the server
		/// </param>
		private void receiveFile (Socket clientSock, string fileName) //Har fjernet string name, da det kommer med filen
		{
			// TO DO Your own code

			//Går igang med at modtage filen
			byte[] clientData = new byte[BUFSIZE];
			byte[] emptyData = new byte[1];

			//Til visning af procent
			int procentBuf = 0;
			double procentKontrol = 0;
			bool disp = true;

			//Til beregning af hastighed
			double gnsHastighed = 0;

			bool stop = false; //Hvis filen under overførsel bliver corrupted (Missing data)

			//Til visning af estimeret tid
			Stopwatch stopWatch = new Stopwatch();  //Bruges til at få manglende tid til 100% tilbage
			double time;
			stopWatch.Start();

			try
			{
				File.Delete(receivedPath + fileName);
				Console.WriteLine("\n Sletter filen før genskrivning");
			}
			catch 
			{
				Console.WriteLine("\n Opretter modtaget file");
			}

			Console.WriteLine("Venter på server...");

			clientSock.Receive(clientData);

			long numVal = BitConverter.ToInt64(clientData, 0);
			Console.WriteLine("Der skal modtages {0} antal gange", numVal);

			if (numVal < 100) //Skal ikke udskrive procent og tid, hvis der kun er under 100 pakker
			{
				disp = false;
			}

			BinaryWriter bWrite = new BinaryWriter(File.Open(receivedPath + fileName, FileMode.Append));

			for(long i = 1; i <= numVal; i = i + 1)
			{
				clientSock.Send(emptyData); //Fortæller serveren at clienten er klar
				//System.Threading.Thread.Sleep(2);//Lader serveren overfører sin data SLOW DOWN

				int receivedBytesLen = clientSock.Receive(clientData);

				if (i > procentKontrol && disp == true) //Fortæl hvor mange % der er tilbage af overførslen
				{
					Console.Clear();
					Console.WriteLine("Venter: {0} procent ud af 100 procent eller {1} pakker ud af {2}.", procentBuf, i, numVal);
					time = stopWatch.Elapsed.TotalSeconds; //Formatere systemtime til double i sekunder
					Console.WriteLine("\n Tid tilbage {0} i sekunder", (time / procentBuf) * (100-procentBuf));
					gnsHastighed = gnsHastighed + ((i/time));
					Console.WriteLine("\n Hastighed: {0} kB/s", ((i/time)));
					procentBuf++;
					procentKontrol = procentBuf * numVal / 100;
				}

				if (receivedBytesLen < BUFSIZE) //kommer herind ved sidste pakke
				{
					Console.Clear();
					Console.WriteLine ("\n Rest data: {0}", (receivedBytesLen-forBites));
					Console.WriteLine("\n Resume:");
					Console.WriteLine ("\n Overførslen tog: {0}.",stopWatch.Elapsed);
					Console.WriteLine("\n Gennemsnits hastighed: {0} kB/s", gnsHastighed/100);
					stopWatch.Stop(); //Stopper stopuret
					bWrite.Write (clientData, forBites, receivedBytesLen-forBites); //Samler filen

					if (stop == true) //Hvis sidste pakke gentages er data corrupted
					{
						Console.WriteLine("\n The file is corrupted");
						break;
					}
					stop = true; //Hvis sidste pakke gentages er data corrupted
				} 
				else 
				{
					bWrite.Write(clientData, forBites, BUFSIZE - forBites); //Samler filen
				}
			}
			bWrite.Close(); //Færdiggør filen til en hel file
		}


		/// <summary>
		/// The entry point of the program, where the program control starts and ends.
		/// </summary>
		/// <param name='args'>
		/// The command-line arguments.
		/// </param>
		public static void Main (string[] args)
		{
			bool run = true;
			while (run) 
			{
				Console.WriteLine ("Client starts...");
				new file_client (args); //Starter class

				bool wrong = true;
				while (wrong) 
				{
					Console.WriteLine ("\n Do you want to recive more files Y/n");
					string choice = Console.ReadLine ();
					Console.Clear ();

					if (choice == "Y") 
					{
						wrong = false;
					} 
					else if (choice == "n") 
					{
						wrong = false;
						run = false;
					} 
					else 
					{
						Console.WriteLine ("\n That wasn't a choice, try again...");
					}
				}
			}
		}
	}
}
