package Applet;

import java.applet.Applet;
import java.awt.Graphics;
import javax.swing.JFrame;

/*
  35. Write a simple Java applet that displays “Welcome to Java Applet”.
*/
public class WelcomeApplet_35 extends Applet {

    @Override
    public void paint(Graphics g) {
        g.drawString("Welcome to Java Applet", 50, 50);
    }

    // Main method to run the applet directly in IntelliJ IDEA
    public static void main(String[] args) {
        JFrame frame = new JFrame("Applet Viewer");
        WelcomeApplet_35 applet = new WelcomeApplet_35();

        applet.init();
        applet.start();

        frame.add(applet);
        frame.setSize(400, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // Center window on screen
        frame.setVisible(true);
    }
}
