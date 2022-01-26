package labpkg;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*; 
import java.util.Date;
  
public class AppletCounter extends Applet{ 
	int x = 0;
	Button increaseButton;
	Button decreaseButton;
	public void init(){
		increaseButton = new Button("increase"); 
		decreaseButton = new Button("decrease"); 
		increaseButton.addActionListener(new ActionListener()
										{
											public void actionPerformed(ActionEvent ev){
											x++ ;
											repaint() ;
											}
										});
		decreaseButton.addActionListener(new ActionListener()
										{
											public void actionPerformed(ActionEvent ev){
											x-- ;
											repaint() ;
											}
										});									
	add(increaseButton);
	add(decreaseButton);
	}
	public void paint(Graphics g){ g.drawString("Click Count is:" + x, 50, 200);
}


}
