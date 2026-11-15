package Exam;

/*
 21. Develop a Java program to demonstrate multithreading using the Thread class.
 */

// Thread class 1
class DownloadTask extends Thread{
    @Override
    public void run() {
        for (int i = 1 ; i<= 5; i++){
            System.out.println("Downloading file... " + i);
        }
    }
}
// Thread class 2
class UploadTask extends Thread{
    @Override
    public void run() {
        for (int i = 1 ; i<= 5; i++){
            System.out.println("Uploading file... " + i);
        }
    }
}
public class Multithreading_21 {

    static void main(String[] args) {

        DownloadTask download = new DownloadTask();
        UploadTask upload = new UploadTask();

        // Start both threads
        download.start();
        upload.start();
    }
}
