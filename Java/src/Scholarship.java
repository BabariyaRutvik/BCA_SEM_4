import java.util.Scanner;

public class Scholarship {

    public static void main(String[] args) {

        String studentName;
        double percentage;
        double familyIncome;

        Scanner sc = new Scanner(System.in);

        // Accept Input
        System.out.print("Enter Student Name: ");
        studentName = sc.nextLine();

        System.out.print("Enter Percentage: ");
        percentage = sc.nextDouble();

        System.out.print("Enter Family Income: ");
        familyIncome = sc.nextDouble();

        // Display Student Details
        System.out.println("\n----- Student Details -----");
        System.out.println("Student Name   : " + studentName);
        System.out.println("Percentage     : " + percentage);
        System.out.println("Family Income  : " + familyIncome);

        // Scholarship Rules
        if (percentage >= 90) {

            if (familyIncome < 300000) {
                System.out.println("Scholarship Status : 100% Scholarship");
            } else {
                System.out.println("Scholarship Status : 50% Scholarship");
            }

        } else if (percentage >= 75 && percentage <= 89.99) {

            if (familyIncome < 300000) {
                System.out.println("Scholarship Status : 25% Scholarship");
            } else {
                System.out.println("Scholarship Status : No Scholarship");
            }

        } else {

            System.out.println("Scholarship Status : No Scholarship");

        }

        sc.close();
    }
}