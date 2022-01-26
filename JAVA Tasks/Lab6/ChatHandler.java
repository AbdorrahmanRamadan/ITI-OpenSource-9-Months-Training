package labpkg;

import java.net.Socket;
import java.io.DataInputStream;
import java.io.PrintStream;
import java.lang.Thread;
import java.util.*;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ChatHandler extends Thread {
  Socket cs;
  DataInputStream dis;
  PrintStream ps;
  static Vector<ChatHandler> clientsVector = new Vector<ChatHandler>();

  public ChatHandler(Socket cs) {
    this.cs = cs;
    try {
      dis = new DataInputStream(cs.getInputStream());
      ps = new PrintStream(this.cs.getOutputStream());
    } catch (IOException ex) {ex.printStackTrace();}
    clientsVector.add(this);
    start();
  }

  public void run() {
    while (true) {
      try {
			String msg = dis.readLine();
			if(msg.equals("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$") ) {
				clientsVector.remove(this);
				break;
					
			}
			for(ChatHandler ch : clientsVector)
			{
				ch.ps.println(msg);
			}      
	  } catch (IOException ex) {ex.printStackTrace();}
    }
  }
}