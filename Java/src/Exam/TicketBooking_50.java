package Exam;

/*
  50. Ticket booking: Demonstrate Thread Life Cycle 
      (New, Runnable, Running, Timed_Waiting/Sleeping, Terminated)
      using sleep(), join(), and isAlive().
*/
public class TicketBooking_50 {

    static class BookingTask extends Thread {
        @Override
        public void run() {
            try {
                // Running state: processing ticket
                System.out.println("Booking Thread: Processing ticket for passenger...");

                // Timed_Waiting state: sleeping for 800ms
                Thread.sleep(800);

                System.out.println("Booking Thread: Ticket booked successfully!");
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted: " + e.getMessage());
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        System.out.println("===== Thread Life Cycle (Ticket Booking) =====\n");

        // 1. NEW State
        BookingTask bookingThread = new BookingTask();
        System.out.println("1. State after creation : " + bookingThread.getState());
        System.out.println("   Is Thread Alive?     : " + bookingThread.isAlive());

        // 2. RUNNABLE State
        bookingThread.start();
        System.out.println("2. State after start()  : " + bookingThread.getState());
        System.out.println("   Is Thread Alive?     : " + bookingThread.isAlive());

        // Short pause to let bookingThread enter sleep()
        Thread.sleep(200);

        // 3. TIMED_WAITING State (Sleeping)
        System.out.println("3. State while sleeping : " + bookingThread.getState());

        // 4. join(): Wait for bookingThread to finish execution
        bookingThread.join();

        // 5. TERMINATED State
        System.out.println("4. State after join()   : " + bookingThread.getState());
        System.out.println("   Is Thread Alive?     : " + bookingThread.isAlive());
    }
}
