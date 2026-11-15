package Applet;

import javax.swing.*;
import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.net.URL;

/*
  38. Develop a Java applet to play an audio file.
*/
public class AudioApplet_38 extends Applet implements ActionListener {

    AudioClip audioClip;
    Button playButton, loopButton, stopButton;

    @Override
    public void init() {
        // Create control buttons
        playButton = new Button("Play");
        loopButton = new Button("Loop");
        stopButton = new Button("Stop");

        // Add action listeners
        playButton.addActionListener(this);
        loopButton.addActionListener(this);
        stopButton.addActionListener(this);

        // Add buttons to applet layout
        setLayout(new FlowLayout());
        add(playButton);
        add(loopButton);
        add(stopButton);

        // Load the audio file
        try {
            // Check in classpath first
            URL audioURL = getClass().getResource("/audio.wav");
            if (audioURL != null) {
                audioClip = Applet.newAudioClip(audioURL);
            } else {
                File audioFile = new File("src/audio.wav");
                if (!audioFile.exists()) {
                    audioFile = new File("audio.wav");
                }
                audioClip = Applet.newAudioClip(audioFile.toURI().toURL());
            }
        } catch (Exception e) {
            System.out.println("Error loading audio: " + e.getMessage());
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (audioClip != null) {
            if (e.getSource() == playButton) {
                audioClip.play(); // Play audio once
            } else if (e.getSource() == loopButton) {
                audioClip.loop(); // Play audio continuously
            } else if (e.getSource() == stopButton) {
                audioClip.stop(); // Stop audio playback
            }
        }
    }

    @Override
    public void stop() {
        // Stop playback when applet stops
        if (audioClip != null) {
            audioClip.stop();
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Applet - Play Audio");
        AudioApplet_38 applet = new AudioApplet_38();

        applet.init();
        applet.start();

        frame.add(applet);
        frame.setSize(400, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null); // Center window on screen
        frame.setVisible(true);
    }
}
