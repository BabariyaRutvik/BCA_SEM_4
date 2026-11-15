package Exam;
/*
 28. Create a Java program for user-defined exceptions such as InvalidAgeException.
 */
class InvalidAgeException extends Exception {
    InvalidAgeException(String message){
        super(message);

    }
}
public class UserDefineException_28 {
    static void checkAge(int age) throws  InvalidAgeException{
        if (age < 18) {
            throw new InvalidAgeException(
                    "Age must be 18 or above."
            );
        }

        System.out.println("You are eligible.");
    }

    public static void main(String[] args) {
        try {

            checkAge(16);

        }
        catch (InvalidAgeException e) {

            System.out.println("Exception: " + e.getMessage());
        }
    }
}
