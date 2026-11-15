package Applet;

import java.applet.Applet;
import java.awt.*;
import javax.swing.JFrame;

/*
  36. Create a Java applet that draws different shapes (rectangle, circle, line).
*/
public class ShapeApplet_36 extends Applet {

    @Override
    public void paint(Graphics g) {
        // Draw line: (x1, y1, x2, y2)
        g.setColor(Color.RED);
        g.drawLine(30, 50, 200, 50);
        g.drawString("Line", 30, 40);

        // Draw rectangle: (x, y, width, height)
        g.setColor(Color.BLUE);
        g.drawRect(30, 80, 150, 80);
        g.drawString("Rectangle", 30, 75);

        // Draw circle: (x, y, width, height)
        g.setColor(Color.MAGENTA);
        g.drawOval(30, 200, 100, 100);
        g.drawString("Circle", 30, 195);
    }

    // Main method to run the applet directly in IntelliJ IDEA
    public static void main(String[] args) {
        JFrame frame = new JFrame("Applet - Draw Shapes");
        ShapeApplet_36 applet = new ShapeApplet_36();

        applet.init();
        applet.start();

        frame.add(applet);
        frame.setSize(350, 380);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // Center window on screen
        frame.setVisible(true);
    }
}
