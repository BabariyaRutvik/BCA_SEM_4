import java.util.Scanner;

public class input_output
{
    static void main(String[] args) {
        // make the Calculation of two numbers
        int a , b;

        Scanner input = new Scanner(System.in);

        System.out.println("Enter 1st Number: ");
        a = input.nextInt();

        System.out.println("Enter 2nd Number: ");
        b = input.nextInt();


        int add;
        add = (a+b);
        System.out.println("Addition is: " + add);

        // substraction
        int sub;
        sub = (a-b);
        System.out.println("Subtraction is: " + sub);

        int mul;
        mul = (a*b);
        System.out.println("Multiplication is: " + mul);

        int div;
        div = (a/b);
        System.out.println("Division is: " + div);


    }


}
