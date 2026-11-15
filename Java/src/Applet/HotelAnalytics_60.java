package Applet;

import java.applet.Applet;
import java.awt.*;
import javax.swing.JFrame;

/*
  60. Hotel analytics: Write a Java applet using Graphics class 
      (drawRect, fillRect, drawString, setColor) to draw a bar chart 
      of monthly hotel bookings passed as applet parameters.

  <applet code="HotelAnalytics_60.class" width="550" height="360">
      <param name="Jan" value="45">
      <param name="Feb" value="70">
      <param name="Mar" value="95">
      <param name="Apr" value="60">
  </applet>
*/
public class HotelAnalytics_60 extends Applet {

    String[] months = {"Jan", "Feb", "Mar", "Apr"};
    int[] bookings = new int[4];
    Color[] barColors = {new Color(220, 50, 50), new Color(50, 100, 220), new Color(40, 160, 40), new Color(240, 140, 20)};

    @Override
    public void init() {
        // Read parameters with fallback defaults for standalone run
        for (int i = 0; i < months.length; i++) {
            String paramVal = null;
            try {
                paramVal = getParameter(months[i]);
            } catch (NullPointerException ignored) {
                // When run in IntelliJ without Applet stub
            }

            if (paramVal != null) {
                try {
                    bookings[i] = Integer.parseInt(paramVal.trim());
                } catch (NumberFormatException e) {
                    bookings[i] = 50;
                }
            } else {
                int[] defaults = {45, 75, 95, 60};
                bookings[i] = defaults[i];
            }
        }
    }

    @Override
    public void paint(Graphics g) {
        // Title
        g.setFont(new Font("Arial", Font.BOLD, 18));
        g.setColor(Color.BLACK);
        g.drawString("Hotel Monthly Bookings Analytics", 120, 40);

        // Chart baseline
        g.drawLine(50, 260, 480, 260);

        int barWidth = 60;
        int spacing = 45;
        int startX = 80;

        g.setFont(new Font("Arial", Font.BOLD, 14));

        for (int i = 0; i < months.length; i++) {
            int x = startX + i * (barWidth + spacing);
            int barHeight = bookings[i] * 2; // Scale factor
            int y = 260 - barHeight;

            // 1. Draw filled bar (fillRect & setColor)
            g.setColor(barColors[i]);
            g.fillRect(x, y, barWidth, barHeight);

            // 2. Draw bar border (drawRect & setColor)
            g.setColor(Color.BLACK);
            g.drawRect(x, y, barWidth, barHeight);

            // 3. Draw count value above bar (drawString)
            g.drawString(String.valueOf(bookings[i]), x + 20, y - 8);

            // 4. Draw month label below bar (drawString)
            g.drawString(months[i], x + 18, 280);
        }
    }

    // Main method to run directly in IntelliJ IDEA
    public static void main(String[] args) {
        JFrame frame = new JFrame("Hotel Analytics - Bar Chart");
        HotelAnalytics_60 applet = new HotelAnalytics_60();

        applet.init();
        applet.start();

        frame.add(applet);
        frame.setSize(550, 360);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
