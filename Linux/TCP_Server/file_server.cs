using System;
using System.IO;
using System.Net;
using System.Net.Sockets;

using System.Text; //Bennyttes til decodning Encoding.ASCII.GetBytes 




namespace tcp
{
	class file_server
	{

		/// <MINE VARIABLER, HUSK AT SÆTTE MIG>
		const int forbytes = 1; //Bit der ligger før modtagelsen i bufferen
		string filePath = @"/root/ikn/Oevelse6/C#/ServerFileFolder/"; //Your File Path;//Hvor ligger servermappen
		/// <MINE VARIABLER, HUSK AT SÆTTE MIG>

		/// <summary>
		/// The PORT
		/// </summary>
		const int PORT = 9000;
		/// <summary>
		/// The BUFSIZE
		/// </summary>
		const int BUFSIZE = 1000; //Må ikke sættes over jombo buffer på lan er den 9000 på wifi er den efter IEEE på 7935

		/// <summary>
		/// Initializes a new instance of the <see cref="file_server"/> class.
		/// Opretter en socket.
		/// Venter på en connect fra en klient.
		/// Modtager filnavn
		/// Finder filstørrelsen
		/// Kalder metoden sendFile
		/// Lukker socketen og programmet
 		/// </summary>
		private file_server ()
		{
			// TO DO Your own code
			try
			{
				string path;
				byte[] bytes = new byte[BUFSIZE]; 
				int bytesRec;
				int count; //Antal filer i mappen
				string [] folder;

				Console.WriteLine ("and connecting to socket...");
				IPEndPoint ipEnd = new IPEndPoint(IPAddress.Any, PORT); //Kontroller alle ip-addresser på den port, fordi den er sat til any
				Socket Sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp ); //InterNetwork means IPV4
				Sock.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.SendTimeout,3000); //Timeout ved sendning
				Sock.Bind(ipEnd);
				Sock.Listen(100);
				//serverSock is the socket object of client, so we can use it now to transfer data to client

				//Venter på en client connector
				Console.WriteLine ("\n SCV Ready...");
				Socket serverSock = Sock.Accept();
				Sock.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout,10000); //Timeout ved modtagelse, Må ikke kaldes, før acceptet, da serveren skal vente på en mullig klient
				serverSock.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.SendTimeout,5000); //Timeout ved sendning

				Console.WriteLine(" >> Acceptet connection from client");

				//Spørger clienten om path
				Console.WriteLine("\n Venter på client, af valg af path");
				bytesRec = serverSock.Receive (bytes);  
				path = @"/"+Encoding.ASCII.GetString (bytes, 0, bytesRec);
				Console.WriteLine ("Valgt path {0}", path); 

				try //Forsøger om mappen eksistere
				{
					//Udskriver mullige filer fra servermappen
					Console.WriteLine("\n Filer på serveren");
					folder = Directory.GetFiles(path);
					foreach(string files in folder)Console.WriteLine(files); //Udskriver alle mullige filer til consol

					//Antal filer i mappen
					count = Directory.GetFiles(path, "*", SearchOption.TopDirectoryOnly).Length;;
					Console.WriteLine("filer i mappen: {0}", count);
				}
				catch //Ellers går vi til default mappen
				{
					Console.WriteLine("\n Path from client didn't match, taking default path");

					path = filePath;

					//Udskriver mullige filer fra servermappen
					Console.WriteLine("\n Filer på serveren");
					folder = Directory.GetFiles(path);
					foreach(string files in folder)Console.WriteLine(files); //Udskriver alle mullige filer til consol

					//Antal filer i mappen
					count = Directory.GetFiles(path, "*", SearchOption.TopDirectoryOnly).Length;;
					Console.WriteLine("filer i mappen: {0}", count);
				}

				//Informere clienten om path af filer
				// Send the data through the socket. 
				Console.WriteLine("\n Sender mullige filer til henting til client");
				string possibleFiles = "";
				for (int i = 1; i <= count; i = i + 1) 
				{
					possibleFiles = possibleFiles + "\n" + folder [i-1];
				}
				byte[] msg = Encoding.ASCII.GetBytes (possibleFiles); 
				serverSock.Send (msg); 


				//file valg fra client
				Console.WriteLine("\n Venter på client, af valg af file");
				bytesRec = serverSock.Receive (bytes);  
				string valg = Encoding.ASCII.GetString (bytes, 0, bytesRec);
				Console.WriteLine ("Valgt file {0}", valg); 

				//Begynder afsendelse til client
				sendFile (valg, serverSock, path);

				Console.WriteLine("\n Lukker forbindelse");
				//lukker ned
				serverSock.Close();
				Sock.Close();				

			}
			catch
			{
				Console.Clear();
				Console.WriteLine("\n Noget gik galt, genstarter...");
			}

		}

		/// <summary>
		/// Sends the file.
		/// </summary>
		/// <param name='fileName'>
		/// The filename.
		/// </param>
		/// <param name='fileSize'>
		/// The filesize.
		/// </param>
		/// <param name='io'>
		/// Network stream for writing to the client.
		/// </param>
		private void sendFile (String fileName, Socket io, string path) //Jeg har fjernet long fileSize(Unødvendig), netstream gav ikke menning da det er en socket
		{
			// TO DO Your own code

			io.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.ReceiveTimeout,5000); //Timeout ved modtagelse
			io.SetSocketOption(SocketOptionLevel.Socket, SocketOptionName.SendTimeout,5000); //Timeout ved sendning

			//byte[] fileData = File.ReadAllBytes(path + fileName); //Alternativ: Indlæser hele file til afsending, max 4,2Gb eller efter hvad maskin har dedikeret af ram
			byte[] fileData = new byte[BUFSIZE-forbytes]; //Benyttes til at lagre dele af filen, som skal sendes
			using(FileStream fs = new FileStream(path + fileName, FileMode.Open, FileAccess.Read)) //Åbner en filestream, til at læse fra en file
			{

				int procentBuf = 0; //Disse 3 funktioner benyttes til at finde procent
				double procentKontrol = 0;
				bool disp = true;

				long count = new System.IO.FileInfo((path + fileName)).Length; //Giver mig file størrelsen uden at læse filen
				byte[] buffer1 = new byte[BUFSIZE]; //Jeg plusser buffersize på for at have en længere, så jeg ikke ender på eksempel 2999, hvor jeg skulle have 3000
				int buffer2 = 0;
				byte[] emptyData = new byte[1]; //Benyttes til respons fra client
				long sendCount = (count / (BUFSIZE-forbytes)) + 1 ; //Devider med buffer, for at få antal gange og da vi runder ned, skal vi have 1+

				if(sendCount >= (BUFSIZE-forbytes))
				{
					//sendCount = sendCount + (sendCount / (BUFSIZE-forbytes)) ; //Sikre at overførslen virker ved over 100kB
				}

				byte[] countBytes = BitConverter.GetBytes(sendCount);

				Console.WriteLine("\n Antal gange der skal sendes: {0}", sendCount);

				io.Send(countBytes);

				for (int i = 1; i <= sendCount; i = i + 1) 	//Begynder sendelse af filen i denne for løkke efter antal af pakker
				{
					//System.Threading.Thread.Sleep(2); //Simulere et delay på netværket, hvis ikke udkommenteret

					io.Receive (emptyData);//Venter på clienten er klar

					if (i > procentKontrol && disp == true) //Fortæl hvor mange % der er tilbage af overførslen
					{
						Console.Clear();
						Console.WriteLine("Venter: {0} procent ud af 100 procent eller {1} pakker ud af {2}.", procentBuf, i, sendCount);
						procentBuf++; //Tæller 1 procent op til næste udskrivning
						procentKontrol = procentBuf * sendCount / 100; //Finder værdi for næste procent i antal pakker
					}

					if (sendCount <= 1) //Ved kun 1 pakke
						{
							Array.Resize(ref buffer1, unchecked((int)(count+forbytes)));
							fs.Read (fileData, buffer2, unchecked((int)count));
							Array.Copy(fileData, buffer2, buffer1, forbytes, count);
						}
						else if (i >= sendCount)//Ved sidste pakke ved flere pakker
						{	
							Console.WriteLine("NO MORE DATA");
							int x = unchecked((int)(count - buffer2));
							Console.WriteLine("Reste data: {0}",x);
							
							fs.Read (fileData, 0, x);
							Array.Resize(ref buffer1, unchecked((int)(x+forbytes)));
							Array.Copy(fileData, 0, buffer1, forbytes, x);
						}	
						else if (buffer2 <= count - BUFSIZE) //Ved flere pakker
						{
							fs.Read (fileData, 0, BUFSIZE-forbytes);
							Array.Copy(fileData, 0, buffer1, forbytes, BUFSIZE-forbytes);
							buffer2 = buffer2 + BUFSIZE-forbytes;
						}

					io.Send (buffer1);
				}

				Console.WriteLine("File: {0} has been sent. With the size: {1} bytes", fileName, count); //Resume af forsendelse
		
			}
		}
		/// <summary>
		/// The entry point of the program, where the program control starts and ends.
		/// </summary>
		/// <param name='args'>
		/// The command-line arguments.
		/// </param>
		public static void Main (string[] args)
		{
			while (true) 
			{
				Console.WriteLine ("Server starts...");
				new file_server (); //Start class
			}
		}
	}
}
