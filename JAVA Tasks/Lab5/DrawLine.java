package labpkg;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;


public class DrawLine extends Applet {

  int xStart = 0 ;
  int yStart = 0 ;
  int xEnd = 0 ;
  int yEnd = 0 ;
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
  public void paint(Graphics g){g.drawLine(xStart, yStart,xEnd,yEnd);}

}
