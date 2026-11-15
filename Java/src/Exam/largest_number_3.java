package Exam;

import java.util.Scanner;

/*
  3. Implement a Java program using control statements to find the largest of three numbers.
 */
public class largest_number_3 {

    static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter 1st number:");
        int num1 = sc.nextInt();

        System.out.println("Enter 2nd number:");
        int num2 = sc.nextInt();

        System.out.println("Enter 3rd number:");
        int num3 = sc.nextInt();

        // nested if else
        if (num1> num2){
            if (num1 > num3){
                System.out.println("Largest Number is: " + num1);
            }
            else{
                System.out.println("Largest Number is: " + num3);
            }
        }
        else {
            if (num2 > num3){
                System.out.println("Largest Number is: " + num2);
            }
            else{
                System.out.println("Largest Number is: " + num3);
            }
        }
    }


}
