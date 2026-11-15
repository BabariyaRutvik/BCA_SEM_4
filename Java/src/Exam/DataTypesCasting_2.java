package Exam;

/*
  2. Develop a Java program to demonstrate the use of different data types and type casting.

 */
public class DataTypesCasting_2
{
    static void main(String[] args) {
        // different data types
        byte b = 10;
        short s = 1000;
        int i = 5000;
        long l = 100000L;
        float f = 12.f;
        double d = 25.75;
        char c = 'a';
        boolean flag = true;

        // display different data types
        System.out.println("Byte: " + b);
        System.out.println("Short: " + s);
        System.out.println("Integer: " + i);
        System.out.println("Long: " + l);
        System.out.println("Float: " + f);
        System.out.println("Double: " + d);
        System.out.println("Character: " + c);
        System.out.println("Boolean: " + flag);

        // widening type casting
        int number = 100;
        double widening =  number;

        System.out.println("\nWidening Type Casting:");
        System.out.println("Integer value: " + number);
        System.out.println("Converted to double: " + widening);

        // Narrowing Type Casting
        double decimal = 99.99;
        int narrowing = (int) decimal;


        System.out.println("\nNarrowing Type Casting:");
        System.out.println("Double value: " + decimal);
        System.out.println("Converted to integer: " + narrowing);
    }
}
