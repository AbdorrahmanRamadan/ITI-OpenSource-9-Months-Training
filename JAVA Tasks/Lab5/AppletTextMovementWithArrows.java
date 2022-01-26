package labpkg;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*; 
import java.util.Date;
import java.awt.FontMetrics;
  
public class AppletTextMovementWithArrows extends Applet{ 
	int textWidth,textHeight, x,y;
	String wordToWrite = "Java";
	public void init(){
		x = (getWidth()-textWidth)/2;
		y = (getHeight()-textHeight)/2;
		this.addKeyListener(new KeyAdapter()
										{
											public void keyPressed(KeyEvent e){
												if(e.getKeyCode() == KeyEvent.VK_RIGHT){
													if(x < getWidth()-(textWidth+5)){
													  x+=10;
													  repaint();
													}
												  }else if(e.getKeyCode() == KeyEvent.VK_LEFT ){
													if(x > 5){
													  x-=10;
													  repaint();
													}
												  }else if(e.getKeyCode() == KeyEvent.VK_UP){
													if(y > 10+(textHeight/2)){
													  y-=10;
													  repaint();
													}
												  }else if(e.getKeyCode() == KeyEvent.VK_DOWN){
													if(y < getHeight()-textHeight/2){
													  y+=10;
													  repaint();
													}
												  }
											}
										});
										
	}
	public void paint(Graphics g){
		FontMetrics fm = g.getFontMetrics();
		textWidth = fm.stringWidth(wordToWrite);
		textHeight = fm.getHeight();
		g.drawString(wordToWrite ,x,y);
	}


}
