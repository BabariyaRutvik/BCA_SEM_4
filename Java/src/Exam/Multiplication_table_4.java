package Exam;

/*
  4. Write a Java program to generate a multiplication table for a given number using loops.
 */

import java.util.Scanner;

public class Multiplication_table_4 {

    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Any Number:");
        int num = sc.nextInt();

        for (int i = 1; i <= 10; i++) {
            System.out.println(num + " x " + i + " = " + (num * i));
        }
    }
}
