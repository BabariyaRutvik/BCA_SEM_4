package Exam;

/*
  19. Write a Java program to implement multiple inheritance using interfaces.
 */
interface CameraFeatures {
    void takePhoto();
}

interface MusicFeatures {
    void playMusic();
}

class SmartphoneDevice implements CameraFeatures, MusicFeatures {
    @Override
    public void takePhoto() {
        System.out.println("Smartphone is taking a photo.");
    }

    @Override
    public void playMusic() {
        System.out.println("Smartphone is playing music.");
    }
}

public class MultipleInheritance_19 {
    public static void main(String[] args) {
        SmartphoneDevice phone = new SmartphoneDevice();

        phone.takePhoto();
        phone.playMusic();
    }
}
