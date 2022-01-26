package labpkg;

import java.applet.*;
import java.awt.*;
import java.awt.FontMetrics;

public class MarqueeDemo extends Applet implements Runnable {
  int x = 150,dx = 10,textWidth;
  String MarqueeText = "Hello Java";
  
  
  public void init(){
	  Thread th = new Thread(this);
	  th.start();
  }
  
  public void paint(Graphics g) {
    g.drawString(MarqueeText, x,50 );
	FontMetrics fm = g.getFontMetrics();
	textWidth = fm.stringWidth(MarqueeText);
  }

  public void run() {
    while (true) {
	  x += dx;
      if  (x > getWidth()) x = 0 - textWidth;
      try {
        Thread.sleep(100);
      }
	  catch (Exception e) {
		e.printStackTrace(); 
	  }
      repaint();
    }
  }
}