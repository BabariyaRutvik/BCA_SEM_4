package Exam;

/*
  8. Develop a Java program to demonstrate constructor overloading.
 */
class Student{
    int rollNo;
    String name;
    int age;

    // Default constructor
    Student(){
        rollNo = 101;
        name = "Dhaval";
        age = 28;
    }
    // constructor with two parameters
    // Constructor with two parameters
    Student(int r, String n) {
        rollNo = r;
        name = n;
        age = 0;
    }

    // Constructor with three parameters
    Student(int r, String n, int a) {
        rollNo = r;
        name = n;
        age = a;
    }
    // method to display the result
    void displayDetails() {
        System.out.println("Roll No: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println();
    }

}
public class Constructor_overloading_8 {
    static void main(String[] args) {

        // calling Default Constructor
        Student student = new Student();

        // Calling constructor with two parameters
        Student student2 = new Student(101, "Rahul");

        // Calling constructor with three parameters
        Student student3 = new Student(102, "Rutvik", 26);


        // Display details
        System.out.println("Student 1:");
        student.displayDetails();

        System.out.println("Student 2:");
        student2.displayDetails();

        System.out.println("Student 3:");
        student3.displayDetails();
    }
}
