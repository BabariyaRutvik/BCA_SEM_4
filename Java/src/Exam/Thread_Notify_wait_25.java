package Exam;

/*
 25 . Implement inter-thread communication using wait() and notify().
 */
class AndroidData{
    synchronized void  loadData(){
        System.out.println("Loading Android data...");

        notify();
    }

    synchronized void displayData(){
        try {
            wait();
        }catch (InterruptedException e){
            System.out.println(e);
        }
        System.out.println("Data Received Successfully");
    }
}
public class Thread_Notify_wait_25
{
    public static void main(String[] args)
    {
        AndroidData androidData = new AndroidData();

        Thread uiThread = new Thread(()->{androidData.displayData();});
        Thread dataThread = new Thread(()->{androidData.loadData();});

        uiThread.start();
        dataThread.start();
    }
}
