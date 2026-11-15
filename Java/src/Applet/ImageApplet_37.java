package Applet;

import javax.swing.*;
import java.applet.Applet;
import java.awt.*;
import java.net.URL;

/*
  37. Write a Java applet to display an image on the screen.
*/
public class ImageApplet_37 extends Applet {

    Image image;

    @Override
    public void init() {
        // Load image from classpath or source directory
        URL imgURL = getClass().getResource("/bmwwal.jpg");
        if (imgURL != null) {
            image = new ImageIcon(imgURL).getImage();
        } else {
            image = new ImageIcon("src/bmwwal.jpg").getImage();
            if (image.getWidth(null) <= 0) {
                image = new ImageIcon("bmwwal.jpg").getImage();
            }
        }
    }

    @Override
    public void paint(Graphics g) {
        if (image != null) {
            // Draw image scaled to fit the window: (image, x, y, width, height, observer)
            g.drawImage(image, 30, 30, 420, 350, this);
        } else {
            g.drawString("Image not found!", 50, 50);
        }
    }

    // Main method to run the applet directly in IntelliJ IDEA
    public static void main(String[] args) {
        JFrame frame = new JFrame("Applet - Display Image");
        ImageApplet_37 applet = new ImageApplet_37();

        applet.init();
        applet.start();

        frame.add(applet);
        frame.setSize(500, 450);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // Center window on screen
        frame.setVisible(true);
    }
}
