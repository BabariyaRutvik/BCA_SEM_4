package Exam;

/*
  7. Write a Java program to create a class Student with attributes and methods. Create objects and display their details.
 */
class Students {
  // attributes
   int rollNo;
   String name;
   int age;
   String course;

   // method to display students details
 void  display(){
   System.out.println("Roll No : "+rollNo);
   System.out.println("Name : "+name);
   System.out.println("Age : "+age);
   System.out.println("Course : "+course);
  System.out.println();
 }
}
public class StudentDemo_7 {
 public static void main(String[] args) {
  Students student1 = new Students();

  student1.rollNo = 101;
  student1.name = "Rutvik";
  student1.age = 26;
  student1.course = "BCA";

  // Creatting 2nd objects for 2nd student
  Students student2 = new Students();

  student2.rollNo = 102;
  student2.name = "Dhaval";
  student2.age = 28;
  student2.course = "BCA";

  // Display details
  System.out.println("Student 1 Details:");
  student1.display();

  System.out.println("Student 2 Details:");
  student2.display();
 }
}
