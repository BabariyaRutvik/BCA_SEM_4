package Exam;

/*
  52. Hospital records: Demonstrate garbage collection by creating and 
      discarding Patient objects, calling System.gc(), and displaying free memory.
*/
public class HospitalRecords_52 {

    static class PatientRecord {
        int id;
        String name;

        public PatientRecord(int id, String name) {
            this.id = id;
            this.name = name;
        }

        @Override
        protected void finalize() throws Throwable {
            System.out.println("Garbage collector cleared Patient ID: " + id);
        }
    }

    public static void main(String[] args) {
        System.out.println("===== Garbage Collection Demo (Hospital Records) =====\n");

        Runtime runtime = Runtime.getRuntime();

        System.out.println("Initial Free Memory : " + runtime.freeMemory() + " bytes");

        // Creating 2000 objects without saving references (eligible for GC)
        for (int i = 1; i <= 2000; i++) {
            new PatientRecord(i, "Patient_" + i);
        }

        System.out.println("Memory after creating 2000 records: " + runtime.freeMemory() + " bytes");

        // Explicitly requesting JVM to run Garbage Collector
        System.out.println("\nCalling System.gc()...");
        System.gc();

        // Brief delay to allow GC thread to run
        try {
            Thread.sleep(200);
        } catch (InterruptedException ignored) {}

        System.out.println("Memory after System.gc()           : " + runtime.freeMemory() + " bytes");
    }
}
