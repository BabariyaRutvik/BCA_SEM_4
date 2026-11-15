package Exam;

import java.io.PrintWriter;

/*
  34. Implement a Java program to demonstrate the use of PrintWriter class for formatted output.
 */
public class PrintWriter_34 {
    static void main(String[] args) {
        PrintWriter writer = new PrintWriter(System.out);

        String name = "Rutvik";
        int age = 26;
        double marks = 98.89;

        writer.println("----- Student Details -----");
        writer.printf("Name   : %s%n", name);
        writer.printf("Age    : %d%n", age);
        writer.printf("Marks  : %.2f%n", marks);

        writer.flush();

    }
}
