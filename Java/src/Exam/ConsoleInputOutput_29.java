package Exam;

import java.util.Scanner;

/*
 29. Write a Java program to read input from the console and display it on the screen.
 */
public class ConsoleInputOutput_29
{
    static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter Your Name:");
        String name = input.nextLine();

        System.out.println("Enter Your Age:");
        int age = input.nextInt();


        System.out.println("\n--- User Details ---");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}
