package labpkg;

import java.applet.*;
import java.awt.*;

public class BallDemo extends Applet implements Runnable {
  int ballRadius = 20, x = 100, y = 50,xMovement = 10, yMovement = 5;
  public void init(){
	  Thread th = new Thread(this);
	  th.start();
  }
  public void paint(Graphics g) {
	  
    g.setColor(Color.red);
    g.fillOval(x , y , ballRadius * 2, ballRadius * 2);
  }

  public void run() {
    while (true) {
      if (x  < 0){
		  xMovement = 10;
	  }
	  if(x > getWidth()-10 - ballRadius*2  ){
		  xMovement = -10;
	  }
      if (y  < 0){
		  yMovement = 5;
	  }
	  if(y > getHeight()-5 - ballRadius*2){
		  yMovement = -5;
	  }
      x += xMovement;
      y += yMovement;
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