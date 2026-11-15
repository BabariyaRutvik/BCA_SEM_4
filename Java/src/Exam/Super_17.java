package Exam;

/*
  17. Write a Java program to demonstrate the use of super keyword to access parent class methods and variables.
 */
class Developer1{
    String language = "Java";

    void displayLanguage() {
        System.out.println("Parent class language: " + language);
    }
}
// child class
class ChildDeveloper  extends Developer1{
    String language = "Kotlin";

    void displayDetails() {

        // Access parent class variable
        System.out.println("Parent language: " + super.language);

        // Access child class variable
        System.out.println("Child language: " + this.language);

        // Access parent class method
        super.displayLanguage();
    }
}
public class Super_17 {

    static void main(String[] args) {
        ChildDeveloper developer = new ChildDeveloper();

        developer.displayDetails();
    }
}
