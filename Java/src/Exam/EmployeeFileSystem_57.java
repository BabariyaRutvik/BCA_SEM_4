package Exam;

import java.io.*;

/*
  57. Employee file system: Append employee records (ID, name, salary) 
      to a text file and search for an employee by ID.
*/
public class EmployeeFileSystem_57 {

    private static final String FILE_NAME = "employees.txt";

    // Method to append an employee record
    public static void appendEmployee(int id, String name, double salary) {
        try (FileWriter fw = new FileWriter(FILE_NAME, true);
             BufferedWriter bw = new BufferedWriter(fw);
             PrintWriter pw = new PrintWriter(bw)) {
            pw.println(id + "," + name + "," + salary);
            System.out.println("Appended -> ID: " + id + ", Name: " + name + ", Salary: ₹" + salary);
        } catch (IOException e) {
            System.out.println("Error appending record: " + e.getMessage());
        }
    }

    // Method to search an employee by ID
    public static void searchEmployeeById(int searchId) {
        System.out.println("\nSearching for Employee ID: " + searchId + "...");
        boolean found = false;

        try (BufferedReader br = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] data = line.split(",");
                if (data.length == 3 && Integer.parseInt(data[0].trim()) == searchId) {
                    System.out.println(">> Employee Found!");
                    System.out.println("ID     : " + data[0].trim());
                    System.out.println("Name   : " + data[1].trim());
                    System.out.println("Salary : ₹" + data[2].trim());
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println(">> Employee ID " + searchId + " NOT found.");
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        System.out.println("===== Employee File System (Append & Search) =====\n");

        // 1. Append records
        appendEmployee(101, "Rutvik Babariya", 55000.00);
        appendEmployee(102, "Amit Sharma", 48000.00);
        appendEmployee(103, "Priya Patel", 62000.00);

        // 2. Search for existing employee
        searchEmployeeById(102);

        // 3. Search for non-existing employee
        searchEmployeeById(999);
    }
}
