package Exam;
/*
 26. Write a Java program to handle multiple exceptions using multiple catch blocks.
 */
public class MultipleCatch_26
{
    static void main(String[] args) {
        try {
            int[] numbers = {10, 20 , 30 , 40 , 50};

            int result = 10 / 0;

            System.out.println("Result: " + result);

            System.out.println(numbers[5]);
        }catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero.");
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Invalid array index.");
        }
    }
}
