package labpkg;

import java.awt.*;
import java.applet.*;

public class FontsDemo extends Applet {

    public void paint(Graphics g) {
		String[] fListUsingToolkit = Toolkit.getDefaultToolkit().getFontList();
		String[] fListUsingGraphicsEnvironment = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();

		for(int i=0; i<fListUsingToolkit.length; i++){
			Font currentFont = new Font(fListUsingToolkit[i], Font.PLAIN , 16);
			g.setFont(currentFont);
			g.drawString(fListUsingToolkit[i], 50 , (50 + (20*i)));
		}
		
		for(int i=0; i<fListUsingGraphicsEnvironment.length; i++){
			Font currentFont = new Font(fListUsingGraphicsEnvironment[i], Font.PLAIN , 16);
			g.setFont(currentFont);
			g.drawString(fListUsingGraphicsEnvironment[i], 350 , (50 + (20*i)));
		}
        		

		
    }
// test files
}