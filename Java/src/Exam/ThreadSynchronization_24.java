package Exam;

/*
 24. Create a Java program to demonstrate synchronization between threads.
 */
class SharedCount{
    private int count = 0;

    // synchronize method
    public synchronized void increment(){
        count ++;

        System.out.println(Thread.currentThread().getName() + " increased Count to :" + count);
    }
    public int getCount() {
        return count;
    }
}
class CounterWorker extends Thread {
    private SharedCount sharedCount;
    public CounterWorker(SharedCount sharedCount) {
        this.sharedCount = sharedCount;
    }
    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            sharedCount.increment();
        }
    }
}
public class ThreadSynchronization_24
{
    static void main(String[] args) {

        SharedCount counter = new SharedCount();

        CounterWorker workerOne = new CounterWorker(counter);
        CounterWorker workerTwo = new CounterWorker(counter);

        workerOne.setName("Thread-1");
        workerTwo.setName("Thread-2");

        workerOne.start();
        workerTwo.start();


    }
}
