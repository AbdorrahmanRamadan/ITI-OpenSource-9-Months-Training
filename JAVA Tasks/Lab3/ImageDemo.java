package labpkg;

import java.awt.*;
import java.applet.*;

public class ImageDemo extends Applet {
    Image picture;

    public void init() {
        picture = getImage(getDocumentBase(), "myImage.png");
    }

    public void paint(Graphics g) {
		g.drawImage(picture, 140, 180, getWidth(), getHeight(), this);
        g.drawImage(picture, 50, 20, 120, 180, this);
    }
}