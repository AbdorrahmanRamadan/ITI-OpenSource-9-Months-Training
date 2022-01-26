package labpkg;

import java.applet.Applet;
import java.awt.*;
import java.util.Date;
  
public class AppletDate extends Applet implements Runnable{ 
	Thread th;	Date d;
	public void init(){
		th = new Thread(this); 
		th.start();
		d = new Date();
	}
	public void paint(Graphics g){ 
		g.drawString(d.toString(), 50, 100);
	}
	public void run(){ 
		while(true){
			d = new Date();
			repaint();
			try {
				Thread.sleep(100);
			}
			catch (Exception e) {
				e.printStackTrace(); 
			}
		}
	}
}
