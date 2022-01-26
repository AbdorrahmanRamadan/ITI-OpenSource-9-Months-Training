package labpkg;

import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;

public class ChatServer {
  ServerSocket serverSocket;

  public ChatServer() {
    try {
      serverSocket = new ServerSocket(5005);
    } catch (IOException ex) {ex.printStackTrace();}
    while (true) {
      try {
        Socket socket = serverSocket.accept();
        new ChatHandler(socket);
      } catch (IOException ex) {ex.printStackTrace();}
    }
  }
  public static void main(String[] args) {
    new ChatServer();
  }
}