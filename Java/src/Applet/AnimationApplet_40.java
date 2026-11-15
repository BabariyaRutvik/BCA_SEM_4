package Applet;

import javax.swing.*;
import java.applet.Applet;
import java.awt.*;

/*
  40. Create a Java applet that demonstrates animation (e.g., moving text).
*/
public class AnimationApplet_40 extends Applet implements Runnable {

    String message = "Welcome to Java Applet Animation!";
    int xCoordinates = 0;
    Thread animationThread;
    boolean isRunning;

    @Override
    public void init() {
        setBackground(Color.BLACK);
    }

    @Override
    public void start() {
        // Start the animation thread (Must set isRunning to true)
        isRunning = true;
        animationThread = new Thread(this);
        animationThread.start();
    }

    @Override
    public void run() {
        while (isRunning) {
            try {
                // Redraw the screen
                repaint();

                // Move the text to the right
                xCoordinates += 5;

                // Reset position when text moves beyond the window width
                if (xCoordinates > getWidth()) {
                    xCoordinates = -350; // Re-enter from the left
                }

                // Control animation speed (delay in milliseconds)
                Thread.sleep(80);
            } catch (InterruptedException e) {
                System.out.println("Animation interrupted: " + e.getMessage());
            }
        }
    }

    @Override
    public void paint(Graphics g) {
        // Set font and color for moving text
        g.setFont(new Font("Arial", Font.BOLD, 22));
        g.setColor(Color.CYAN);

        // Draw moving text at (xCoordinates, 100)
        g.drawString(message, xCoordinates, 100);
    }

    @Override
    public void stop() {
        // Stop running when applet stops
        isRunning = false;
        animationThread = null;
    }

    // Main method to run directly in IntelliJ IDEA
    public static void main(String[] args) {
        JFrame frame = new JFrame("Applet - Moving Text Animation");
        AnimationApplet_40 applet = new AnimationApplet_40();

        applet.init();
        applet.start();

        frame.add(applet);
        frame.setSize(550, 220);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // Center window on screen
        frame.setVisible(true);
    }
}
