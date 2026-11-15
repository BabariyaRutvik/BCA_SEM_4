package Applet;

import javax.swing.*;
import java.applet.Applet;
import java.awt.*;

/*
  39. Write a Java applet that accepts parameters from an HTML file and displays them.
*/
public class ParamApplet_39 extends Applet {

    String name;
    String message;

    @Override
    public void init() {
        try {
            // Read parameters passed from HTML file
            name = getParameter("userName");
            message = getParameter("msg");
        } catch (NullPointerException e) {
            // When run directly via main() in IntelliJ, Applet stub is null
        }

        // Default values if run directly via main() without HTML
        if (name == null) {
            name = "Rutvik";
        }
        if (message == null) {
            message = "Welcome to Java Applet Parameters!";
        }
    }

    @Override
    public void paint(Graphics g) {
        g.setFont(new Font("Times New Roman", Font.BOLD, 20));
        g.setColor(Color.BLUE);

        // Display the accepted parameters on screen
        g.drawString("Name: " + name, 50, 60);
        g.drawString("Message: " + message, 50, 100);
    }

    // Main method to run directly in IntelliJ IDEA
    public static void main(String[] args) {
        JFrame frame = new JFrame("Applet - HTML Parameters");
        ParamApplet_39 applet = new ParamApplet_39();

        applet.init();
        applet.start();

        frame.add(applet);
        frame.setSize(450, 220);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // Center window on screen
        frame.setVisible(true);
    }
}
