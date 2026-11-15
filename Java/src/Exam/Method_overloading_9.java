package Exam;

/*
  9. Write a Java program to illustrate method overloading using arithmetic operations.
 */

class Calculator{
    // addition of two integers
    int add(int a,int b){
        return a+b;
    }
    // addition of three integers
    int add(int a,int b,int c){
        return a+b+c;
    }
    // addition of two double values
    double add(double a,double b){
        return a+b;
    }
}
public class Method_overloading_9
{
    public static void main(String[] args)
    {
       Calculator calc = new Calculator();

        // Calling overloaded methods
        System.out.println("Addition of two integers: " + calc.add(10, 20));

        System.out.println("Addition of three integers: " + calc.add(10, 20, 30));

        System.out.println("Addition of two decimal numbers: " + calc.add(10.5, 20.5));
    }
}
