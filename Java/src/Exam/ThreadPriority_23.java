package Exam;

/*
 23. Write a Java program to illustrate thread priorities and their effects.
 */
class LowPriority  extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Low Priority Thread: " + i);
        }
    }
}
class HighPriorityWorker extends Thread {

    @Override
    public void run() {

        for (int i = 1; i <= 5; i++) {
            System.out.println("High Priority Thread: " + i);
        }
    }
}
public class ThreadPriority_23
{
    public static void main(String[] args)
    {
        LowPriority lowThread = new LowPriority();
        HighPriorityWorker highThread = new HighPriorityWorker();


        // set thread priority
        lowThread.setPriority(Thread.MIN_PRIORITY);
        highThread.setPriority(Thread.MAX_PRIORITY);

        System.out.println("Low Thread Priority: " + lowThread.getPriority());
        System.out.println("High Thread Priority: " + highThread.getPriority());

        // Start threads
        lowThread.start();
        highThread.start();

    }
}
