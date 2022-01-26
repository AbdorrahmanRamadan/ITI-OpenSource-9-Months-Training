package labpkg;

import java.applet.Applet; 
import java.awt.Graphics;

public class HelloApplet extends Applet{
	
	public void paint(Graphics g){
		g.drawString("Hello Java", 50, 100);
		String myParam   = getParameter("myParam");
		g.drawString(myParam, 50, 120);
	}
}
