package Exam;

import java.util.Scanner;

/*
  56. Restaurant billing: Demonstrate predefined streams 
      (System.in, System.out, System.err) by reading items and quantities, and printing bill.
*/
public class RestaurantBilling_56 {
    public static void main(String[] args) {
        // System.out: Standard Output
        System.out.println("===== Restaurant Billing (Predefined Streams) =====\n");

        Scanner scanner = new Scanner(System.in);
        double itemPrice = 150.00;

        System.out.print("Enter Item Name: ");
        String itemName = scanner.hasNextLine() ? scanner.nextLine() : "Paneer Pizza";

        System.out.print("Enter Quantity: ");
        int quantity = 0;

        try {
            String qtyStr = scanner.hasNextLine() ? scanner.nextLine() : "2";
            quantity = Integer.parseInt(qtyStr);

            if (quantity <= 0) {
                // System.err: Standard Error
                System.err.println("Error: Quantity must be greater than zero!");
                return;
            }
        } catch (NumberFormatException e) {
            // System.err: Standard Error
            System.err.println("Error: Invalid numeric quantity entered!");
            return;
        }

        double totalAmount = quantity * itemPrice;

        // System.out for printing the final bill
        System.out.println("\n---------- Final Bill ----------");
        System.out.println("Item Name     : " + itemName);
        System.out.println("Price / Item  : ₹" + itemPrice);
        System.out.println("Quantity      : " + quantity);
        System.out.println("Total Amount  : ₹" + totalAmount);
        System.out.println("--------------------------------");
    }
}
