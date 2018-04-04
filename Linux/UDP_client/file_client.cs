using System;
using System.IO;
using System.Net;
using System.Net.Sockets;

//IKN's bib, benyttes til at finde path og file ved indsættelse via. exe

using System.Text; //Bennyttes til decodning Encoding.ASCII.GetBytes
using System.Diagnostics; //Bruges til stopWatch() funktioner
using System.Threading; //Tid til sekunder

namespace udp
{
	class file_client
	{
		/// <MINE VARIABLER, HUSK AT SÆTTE MIG>
		const int forBites = 0; //Bit der ligger før modtagelsen i bufferen
		/// <MINE VARIABLER, HUSK AT SÆTTE MIG>

		/// <summary>
		/// The PORT.
		/// </summary>
		const int PORT = 9002;
		/// <summary>
		/// The BUFSIZE.
		/// </summary>
		const int BUFSIZE = 51;//Må ikke sættes over jombo buffer på lan er den 8960 på wifi er den efter IEEE på 7895. Default uden jumbo er 1460-"70"fra de 4 TCP layer så 1382

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
				Socket clientSock = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp );
				//clientSock.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout,3000); //Timeout ved modtagelse
				//clientSock.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.SendTimeout,3000); //Timeout ved sendning

				//Connector til server
				clientSock.Connect(ipEnd);
				Console.WriteLine("\n Connection succes"); 

				//Du vælger char
				Console.WriteLine("\n Write the L/l loadAvg eller U/u for upTime, to recive from server");
				string choice = Console.ReadLine();
				Console.WriteLine("\n you wrote");
				Console.WriteLine(choice);
				byte[] msg = Encoding.ASCII.GetBytes (choice); 
				clientSock.Send (msg);

				//Går igang med at modtage
				receiveFile (clientSock); //Starter modtagelse

				Console.WriteLine("Server: {0} connected", clientSock.RemoteEndPoint);
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
		private void receiveFile (Socket clientSock) //Har fjernet string name, da det kommer med filen
		{
			// TO DO Your own code

			//Går igang med at modtage filen
			byte[] clientData = new byte[BUFSIZE];
			//byte[] checkSum = new byte[BUFSIZE]; 

			//Til visning af estimeret tid
			Stopwatch stopWatch = new Stopwatch();  //Bruges til at få manglende tid til 100% tilbage
			stopWatch.Start();

			//Til udskrivning af modtaget data
			int receivedBytesLen = clientSock.Receive(clientData);
			Console.Clear();
			Console.WriteLine ("Print from server: {0}", Encoding.ASCII.GetString (clientData, 0, receivedBytesLen));
			Console.WriteLine ("\n Meddelses længde: {0}", (receivedBytesLen));
			Console.WriteLine ("\n Overførslen tog: {0}.",stopWatch.Elapsed);


			stopWatch.Stop(); //Stopper stopuret
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
