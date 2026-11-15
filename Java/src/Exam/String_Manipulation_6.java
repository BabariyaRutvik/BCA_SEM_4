package Exam;

import java.util.Scanner;

/*
 6. Implement a Java program to demonstrate the use of string manipulation methods.
 */
public class String_Manipulation_6 {
    static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a Strings:");
        String str = scanner.nextLine();

        System.out.println("\n Original String: " + str);

        // length of the screen
        System.out.println("Length: " + str.length());

        // convert to uppercase
        System.out.println("Uppercase: " + str.toUpperCase());

        // convert  to lowercase
        System.out.println("Lowercase: " + str.toLowerCase());

        // Character at a Specific position
        System.out.println("Character at index 0: " + str.charAt(0));

        // substring
        if (str.length() >= 3){
            System.out.println("Substring (0 to 3) :" +str.replace('a','x'));


            // concatenation
            String newStr = str.concat("Android");
            System.out.println("After Concatenation: " + newStr);

            // check Equality
            String str2 = "Hello";

            System.out.println("Equals 'Hello': " + str.equals("Hello"));

        }




    }
}
