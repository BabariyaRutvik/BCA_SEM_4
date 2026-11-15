package Exam;
/*
 41. Bank: Write a Java program to create a BankAccount class with a copy constructor
 and use it to create a duplicate account from an existing one.
 */
class BankAccount{
    private String accountNumber;
    private String accountHolderName;
    private double balance;

    // parameterised constructor
    public BankAccount(String accountNumber, String accountHolderName, double balance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = balance;
    }
    // Copy Constructor (Creates a duplicate account from an existing object)
    public BankAccount(BankAccount otherAccount) {
        this.accountNumber = otherAccount.accountNumber;
        this.accountHolderName = otherAccount.accountHolderName;
        this.balance = otherAccount.balance;
    }
    // Method to display account details
    public void displayDetails() {
        System.out.println("Account Number : " + accountNumber);
        System.out.println("Account Holder : " + accountHolderName);
        System.out.println("Balance        : ₹" + balance);
        System.out.println("----------------------------------------");
    }
}
public class BankAccount_41
{
    public static void main(String[] args) {
        System.out.println("-------------------Bank Account -----------------\n");

        // Creating the original account using parameterised constructor
        BankAccount originalAccount = new BankAccount("SBI100200300", "Rutvik Babariya", 50000.75);

        System.out.println("Original Account Details:");
        originalAccount.displayDetails();
        // 2. Creating a duplicate account using the copy constructor
        BankAccount duplicateAccount = new BankAccount(originalAccount);
        System.out.println("Duplicate Account Details (Created via Copy Constructor):");
        duplicateAccount.displayDetails();
    }
}
