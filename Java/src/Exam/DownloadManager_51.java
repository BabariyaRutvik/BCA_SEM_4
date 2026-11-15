package Exam;

/*
  51. Download manager: Demonstrate suspending, resuming, and stopping 
      a thread safely using flags (pause, resume, stop).
*/
public class DownloadManager_51 {

    static class Downloader extends Thread {
        private volatile boolean running = true;
        private volatile boolean paused = false;

        public void pauseDownload() {
            paused = true;
            System.out.println("\n[Action] Download PAUSED.");
        }

        public synchronized void resumeDownload() {
            paused = false;
            notify();
            System.out.println("\n[Action] Download RESUMED.");
        }

        public void stopDownload() {
            running = false;
            resumeDownload(); // Wake up thread if it is waiting
            System.out.println("\n[Action] Download STOPPED.");
        }

        @Override
        public void run() {
            int progress = 0;
            while (running && progress <= 100) {
                synchronized (this) {
                    while (paused && running) {
                        try {
                            wait();
                        } catch (InterruptedException e) {
                            return;
                        }
                    }
                }
                if (!running) break;

                System.out.print("Downloading progress: " + progress + "%  \r");
                progress += 20;

                try {
                    Thread.sleep(400);
                } catch (InterruptedException e) {
                    break;
                }
            }
            if (running && progress > 100) {
                System.out.println("\nDownload Complete (100%)!");
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        System.out.println("===== Download Manager (Thread Suspend, Resume & Stop) =====\n");

        Downloader downloadTask = new Downloader();
        downloadTask.start();

        // Let download run for 800ms
        Thread.sleep(800);
        downloadTask.pauseDownload();

        // Stay paused for 1000ms
        Thread.sleep(1000);
        downloadTask.resumeDownload();

        // Let it run a bit then stop safely
        Thread.sleep(600);
        downloadTask.stopDownload();

        downloadTask.join();
        System.out.println("Main thread exiting safely.");
    }
}
