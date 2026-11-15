package Exam;

/*
 27. Develop a Java program to demonstrate the use of throw, throws, and finally.
 */
public class ThrowThrowsFinally_27
{
    static void checkAge(int age) throws Exception {
        if (age < 18 ){
            // throw creates and raises an exception
            throw new Exception("Age must be 18 or above.");
        }
        System.out.println("Eligible for voting");

    }
    public static void main(String[] args) {
        try {
            checkAge(16);
        }
        catch (Exception e){
            System.out.println("Exception: " + e.getMessage());
        }
        finally {
            System.out.println("Finally block executed.");
        }
    }
}
