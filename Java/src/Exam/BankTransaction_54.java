package Exam;

/*
  54. Bank transaction: Demonstrate nested try-catch blocks with 
      a finally clause during withdraw and deposit operations.
*/
public class BankTransaction_54 {
    public static void main(String[] args) {
        System.out.println("===== Bank Transaction (Nested Try-Catch & Finally) =====\n");

        double accountBalance = 10000.00;

        // Outer try block: Handles transaction lifecycle
        try {
            System.out.println("Initial Balance: ₹" + accountBalance);

            // Nested try block 1: Deposit operation
            try {
                String depositInput = "3000";
                double depositAmount = Double.parseDouble(depositInput);
                if (depositAmount <= 0) {
                    throw new IllegalArgumentException("Deposit amount must be positive.");
                }
                accountBalance += depositAmount;
                System.out.println("Deposit Successful (+₹" + depositAmount + "). Balance: ₹" + accountBalance);
            } catch (IllegalArgumentException e) {
                System.out.println("Deposit Failed: " + e.getMessage());
            }

            // Nested try block 2: Withdraw operation
            try {
                double withdrawAmount = 15000.00; // More than available balance
                if (withdrawAmount > accountBalance) {
                    throw new ArithmeticException("Insufficient funds! Cannot withdraw ₹" + withdrawAmount);
                }
                accountBalance -= withdrawAmount;
                System.out.println("Withdrawal Successful (-₹" + withdrawAmount + "). Balance: ₹" + accountBalance);
            } catch (ArithmeticException e) {
                System.out.println("Withdrawal Failed: " + e.getMessage());
            }

        } catch (Exception e) {
            System.out.println("General Transaction Exception: " + e.getMessage());
        } finally {
            // Finally block always executes
            System.out.println("\n[Finally Block] Transaction session ended.");
            System.out.println("Final Account Balance: ₹" + accountBalance);
            System.out.println("Please collect your receipt.");
        }
    }
}
