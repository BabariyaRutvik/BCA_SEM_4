package Applet;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JFrame;

/*
  59. Applet life cycle: Demonstrate life cycle methods 
      (init, start, stop, destroy and paint) by displaying status messages.

  <applet code="AppletLifeCycle_59.class" width="500" height="300">
  </applet>
*/
public class AppletLifeCycle_59 extends Applet {

    StringBuilder statusLog = new StringBuilder();

    @Override
    public void init() {
        statusLog.append("1. init() called -> Applet initialized\n");
        System.out.println("init() invoked");
    }

    @Override
    public void start() {
        statusLog.append("2. start() called -> Applet started\n");
        System.out.println("start() invoked");
    }

    @Override
    public void paint(Graphics g) {
        statusLog.append("3. paint() called -> UI rendered\n");
        System.out.println("paint() invoked");

        g.setFont(new Font("Arial", Font.BOLD, 15));
        g.setColor(Color.BLUE);

        String[] lines = statusLog.toString().split("\n");
        int y = 50;
        for (String line : lines) {
            g.drawString(line, 30, y);
            y += 35;
        }
    }

    @Override
    public void stop() {
        System.out.println("4. stop() invoked -> Applet execution stopped");
    }

    @Override
    public void destroy() {
        System.out.println("5. destroy() invoked -> Resources released");
    }

    // Main method to run directly in IntelliJ IDEA
    public static void main(String[] args) {
        JFrame frame = new JFrame("Applet Life Cycle Demo");
        AppletLifeCycle_59 applet = new AppletLifeCycle_59();

        applet.init();
        applet.start();

        frame.add(applet);
        frame.setSize(500, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
