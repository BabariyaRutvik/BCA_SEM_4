package Exam;

/*
 22 . Implement a multithreading example using the Runnable interface.
 */

class MessageTask implements Runnable {
    @Override
    public void run() {

        for (int i = 1; i <= 5; i++) {
            System.out.println("Message task running: " + i);
        }
    }
}
class  CalculationTask implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Calculation task running: " + i);
        }
    }
}
public class MultiThread_Runnable_22
{
    static void main(String[] args) {

        // Create Runnable objects
        MessageTask messageTask = new MessageTask();
        CalculationTask calculationTask = new CalculationTask();

        // Create Thread objects
        Thread messageThread = new Thread(messageTask);
        Thread calculationThread = new Thread(calculationTask);

        // Start both threads
        messageThread.start();
        calculationThread.start();
    }
}
