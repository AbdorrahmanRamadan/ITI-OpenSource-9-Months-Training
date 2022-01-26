package labpkg;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;


public class DragBall extends Applet {

  int x =getX();
  int y =getY();
  boolean flagForMouseButtonPressed;

  public void init(){

		x = getWidth()/2 ;
		y = getHeight()/2 ;
		this.addMouseListener(new MouseAdapter(){
					
					public void mousePressed(MouseEvent e){
					  if(e.getX() >= x && e.getX() < x && e.getY() >= y && e.getY() < y){
						  repaint();
					  } 
					  else
					  {	
						x = e.getX() ;
						y = e.getY() ;
						if(x < getWidth() && y < getHeight()){
							 repaint();
						}
					  }
					}
		});

		this.addMouseMotionListener(new MouseMotionAdapter(){
					public void mouseDragged(MouseEvent e){
						x = e.getX() ;
						y = e.getY() ;
						if(x <= getWidth() && y < getHeight() && x > 0 && y > 0){
							 repaint();
						}
					}
		});
  }
  public void paint(Graphics g){g.fillOval(x-25,y-25,50,50);}
}
