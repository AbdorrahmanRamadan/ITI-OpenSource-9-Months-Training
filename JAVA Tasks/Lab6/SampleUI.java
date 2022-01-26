package labpkg;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.awt.*;
import java.net.Socket;
import java.net.InetAddress;


public class SampleUI extends JFrame implements Runnable {
  Socket socket;
  JTextArea textarea = new JTextArea(20, 50);
  JScrollPane scrollPane = new JScrollPane(textarea);
  JTextField textField = new JTextField(40);
  JButton sendButton = new JButton("Send");
  PrintStream printStream;
  BufferedReader dataInputStream;
  boolean running = true;

  public SampleUI() {
    try {
      socket = new Socket(InetAddress.getLocalHost(), 5005);
      dataInputStream = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
      printStream = new PrintStream(socket.getOutputStream());
    } catch (IOException ex) {ex.printStackTrace();}
    
	setLayout(new FlowLayout());
    sendButton.addActionListener((ActionEvent event) -> {
      String message = textField.getText();
      printStream.println(message);
      textField.setText("");
    });
    add(scrollPane);
    add(textField);
    add(sendButton);
    Thread t  = new Thread(this);
	t.start();
	
  this.addWindowListener(new WindowAdapter(){
		public void windowClosing(WindowEvent e) {
				try{
					running = false;
					printStream.println("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
					printStream.close();
					dataInputStream.close();
					socket.close();
				} 
				catch (IOException ex)
				{
					ex.printStackTrace();
				}
				System.exit(0);
			}
		});
		
  }

  public static void main(String args[]) {
    SampleUI sampleUI = new SampleUI();
    sampleUI.setSize(600, 400);
    sampleUI.setResizable(true);
    sampleUI.setVisible(true);
  }

  public void run()
		{
			while (running) {
				try {
				String message = dataInputStream.readLine();
				textarea.append(message + "\n");
				} catch (IOException ex) {//ex.printStackTrace();
				}
			}	
		}
	
}