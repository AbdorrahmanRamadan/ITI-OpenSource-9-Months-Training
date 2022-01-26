package labpkg;

import java.applet.Applet;  
import java.awt.*;  
  
public class AppletLamp extends Applet{  
  
	public void paint(Graphics g){ 
		
		//topOval
		g.drawOval(200,200,500,100); 
		g.setColor(Color.YELLOW);
          	g.fillOval(200,200,500,100);
		

		//threeOvals
		//center
		g.fillOval(375,350,150,300);
		//left
          	g.fillOval(200,400,100,150);
          	//right
		g.fillOval(600,400,100,150);

          	g.setColor(Color.BLACK);
		g.drawOval(375,350,150,300);
		//left
          	g.drawOval(200,400,100,150);
          	//right
		g.drawOval(600,400,100,150);

		//two Lines & connecting arc
		//left
          	g.drawLine(200,250,100,675);
		//right
         	g.drawLine(700,250,800,675);
		//connecting arc
         	g.drawArc(100, 625 , 700 , 100,-180,180);

		//twoLines
          	g.drawLine(425,725,375,875);
          	g.drawLine(475,725,525,875);

		//base
          	g.drawRect(200 , 875 , 500 , 60);
  
  
}  
}  
