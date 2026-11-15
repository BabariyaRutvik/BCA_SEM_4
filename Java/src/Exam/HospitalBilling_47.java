package Exam;

/*
  47. Hospital billing: Write a Java program to demonstrate inheritance on interfaces,
      where interface Payment extends interface Billing, implemented by a PatientBill class.
*/
public class HospitalBilling_47 {

    // 1. Base Interface
    interface Billing {
        void generateBill(double doctorFee, double medicineCharge);
    }

    // 2. Child Interface extending Base Interface (Interface Inheritance)
    interface Payment extends Billing {
        void processPayment(String paymentMode);
    }

    // 3. Class implementing the child interface
    static class PatientBill implements Payment {
        String patientName;
        double totalAmount;

        public PatientBill(String patientName) {
            this.patientName = patientName;
        }

        @Override
        public void generateBill(double doctorFee, double medicineCharge) {
            totalAmount = doctorFee + medicineCharge;
            System.out.println("Patient Name    : " + patientName);
            System.out.println("Doctor Fee      : ₹" + doctorFee);
            System.out.println("Medicine Charge : ₹" + medicineCharge);
            System.out.println("Total Bill      : ₹" + totalAmount);
        }

        @Override
        public void processPayment(String paymentMode) {
            System.out.println("Payment Mode    : " + paymentMode);
            System.out.println("Payment Status  : Successfully Paid ₹" + totalAmount);
        }
    }

    public static void main(String[] args) {
        System.out.println("===== Hospital Billing (Interface Inheritance) =====\n");

        PatientBill bill = new PatientBill("Rutvik Babariya");

        // Calling method from Billing interface
        bill.generateBill(800.00, 1200.00);

        System.out.println("----------------------------------------");

        // Calling method from Payment interface
        bill.processPayment("UPI / Net Banking");
    }
}
