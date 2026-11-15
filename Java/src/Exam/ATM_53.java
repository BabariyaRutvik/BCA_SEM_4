package Exam;

/*
  53. ATM: Demonstrate inbuilt exceptions 
      (ArrayIndexOutOfBoundsException, NumberFormatException, 
       NullPointerException, ArithmeticException).
*/
public class ATM_53 {
    public static void main(String[] args) {
        System.out.println("===== ATM Inbuilt Exceptions Demo =====\n");

        // 1. ArrayIndexOutOfBoundsException (Accessing invalid PIN index)
        try {
            int[] customerPins = {1111, 2222, 3333};
            System.out.println("Accessing customerPins[5]: " + customerPins[5]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("1. ArrayIndexOutOfBoundsException Caught: " + e.getMessage());
        }

        // 2. NumberFormatException (Invalid numeric PIN input)
        try {
            String enteredPin = "12AB";
            int pin = Integer.parseInt(enteredPin);
        } catch (NumberFormatException e) {
            System.out.println("2. NumberFormatException Caught: " + e.getMessage());
        }

        // 3. NullPointerException (Null cardholder object)
        try {
            String cardHolderName = null;
            System.out.println("Card Holder: " + cardHolderName.toUpperCase());
        } catch (NullPointerException e) {
            System.out.println("3. NullPointerException Caught: Object is null");
        }

        // 4. ArithmeticException (Dividing withdrawal by zero denomination)
        try {
            int withdrawAmount = 5000;
            int denomination = 0;
            int count = withdrawAmount / denomination;
        } catch (ArithmeticException e) {
            System.out.println("4. ArithmeticException Caught: " + e.getMessage());
        }
    }
}
