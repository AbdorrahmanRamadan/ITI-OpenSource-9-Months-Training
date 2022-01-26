package labpkg;

import java.io.*; 
import java.net.*; 
  
class Client { 
	Socket mySocket;
	DataInputStream dis ;
	PrintStream ps;
	static String messageToBeSent = "";
	public static void main(String[] args)
	{
		for(String data : args){ 
				messageToBeSent += data +" ";
			}
		messageToBeSent += "\n";
		new Client();
	}
	public Client(){
		try{
			mySocket = new Socket("localhost", 5005);
			dis = new DataInputStream(mySocket.getInputStream());
			ps = new PrintStream(mySocket.getOutputStream()); 
			ps.print(messageToBeSent);
			String replyMsg = dis.readLine();
			System.out.println(replyMsg);	
		}
		catch(IOException ex)
		{
			ex.printStackTrace();
		}
		try
		{
			ps.close();
			dis.close();
			mySocket.close();
		} 
		catch(Exception ex)
		{
			ex.printStackTrace();
		}

	}
} 