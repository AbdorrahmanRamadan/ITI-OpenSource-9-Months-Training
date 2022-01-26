package labpkg;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
import java.util.*;


public class DrawLines extends Applet {
  int xStart = 0 ;
  int yStart = 0 ;
  int xEnd = 0 ;
  int yEnd = 0 ;
  boolean mouseDown = false;
  public class Line{
	  int xStart = 0 ;
	  int yStart = 0 ;
	  int xEnd = 0 ;
	  int yEnd = 0 ;
  }
  ArrayList<Line> linesList = new ArrayList<Line>();
  public void init(){
      this.addMouseListener(new MouseAdapter(){
								
								public void mousePressed(MouseEvent e){
								  xStart = e.getX() ;
								  yStart = e.getY() ;
								}
								public void mouseReleased(MouseEvent e){
								  xEnd = e.getX() ;
								  yEnd = e.getY() ;
								  if(xStart != xEnd && yStart != yEnd ){
									Line l = new Line(); 
									l.xStart = xStart;
									l.yStart = yStart ;
									l.xEnd = xEnd ;
									l.yEnd = yEnd ;
									linesList.add(l);
									repaint();
								  }
								}
							});
      this.addMouseMotionListener(new MouseMotionAdapter(){
									public void mouseDragged(MouseEvent e){
										xEnd = e.getX() ;
										yEnd = e.getY() ;
										if((xStart != xEnd) && (yStart != yEnd) ){
										  repaint();
										}
									}
								  });
  }
  public void paint(Graphics g){g.drawLine(xStart, yStart,xEnd,yEnd);for(Line l:linesList){g.drawLine(l.xStart, l.yStart,l.xEnd,l.yEnd);}}

}
