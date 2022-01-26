package labpkg;

import java.applet.*;
import java.awt.*;
import java.awt.event.*; 


public class BallDemoWithStopAndPause extends Applet implements Runnable {
	int ballRadius = 20, x = 100, y = 50,xMovement = 10, yMovement = 5 , firstClick=-1;
  
	Button increaseButton;
	Button decreaseButton;
	public int getfirstClick(){firstClick++; return firstClick;}
	public void init(){
		increaseButton = new Button("start"); 
		decreaseButton = new Button("pause"); 
		Thread t = new Thread(this);
		increaseButton.addActionListener(new ActionListener()
										{
											public void actionPerformed(ActionEvent ev){
											if (getfirstClick()==0)
												t.start();
											else
												t.resume();
											}
										});
		decreaseButton.addActionListener(new ActionListener()
										{
											public void actionPerformed(ActionEvent ev){
											t.suspend() ;
											}
										});									
	add(increaseButton);
	add(decreaseButton);
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