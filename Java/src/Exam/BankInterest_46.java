package Exam;
/*
  46. Bank interest: Write a Java program to demonstrate the final keyword
      (final variable for interest rate, final method and final class).
*/
public class BankInterest_46 {

    // base class demonstrative final variables and final method
    static class Bank{
        // final; variable variable value not changed
        final double INTEREST_RATE  = 7.5;

        // Final method: cannot be overridden by subclasses
        final void displayInterestPolicy() {
            System.out.println("Bank Fixed Interest Rate: " + INTEREST_RATE + "%");
        }
    }

    // 2. Final class: cannot be inherited (subclassed) by any other class
    static final class SecureAccount extends Bank {
        double principal;
        public SecureAccount(double principal) {
            this.principal = principal;
        }
        public void calculateInterest() {
            double interest = (principal * INTEREST_RATE) / 100;
            System.out.println("Principal Amount : ₹" + principal);
            System.out.println("Yearly Interest  : ₹" + interest);
        }
    }

    public static void main(String[] args) {
        System.out.println("===== Final Keyword Demo =====\n");
        SecureAccount acc = new SecureAccount(50000.00);
        // Calling final method
        acc.displayInterestPolicy();
        // Calculating interest using final variable
        acc.calculateInterest();
    }
}
