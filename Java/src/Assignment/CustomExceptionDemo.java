package Assignment;

/*
 2. Write a Java program to demonstrate custom exception handling.
 */
// Custom Exception Class
class InvalidNumberException extends Exception {

    public InvalidNumberException(String message) {
        super(message);
    }
}

// Main Class
public class CustomExceptionDemo {

    // Method to check number
    static void checkNumber(int number) throws InvalidNumberException {

        if (number < 0) {
            throw new InvalidNumberException("Negative numbers are not allowed.");
        }

        System.out.println("Valid Number: " + number);
    }

    public static void main(String[] args) {

        int number = -10;

        try {
            checkNumber(number);
        }
        catch (InvalidNumberException e) {
            System.out.println("Custom Exception: " + e.getMessage());
        }
    }
}
