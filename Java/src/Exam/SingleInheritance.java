package Exam;

/*
  13. Write a Java program to implement single inheritance (base and derived class).
 */
class User1 {
    int id;
    String name;
    String email;

    void setUser(int id, String name, String email) {
        this.id = id;
        this.name = name;
        this.email = email;
    }
    void displayUser() {
        System.out.println("ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Email: " + email);

    }
}
class Android extends User1 {
    String language;

    void setDevelopersDetails(String language) {
        this.language = language;
    }
    void displayDeveloperDetails() {
        displayUser();
        System.out.println("Programming Language: " + language);
    }
}
public class SingleInheritance {

    static void main(String[] args) {
        Android android = new Android();

        android.setUser(101, "Rutvik", "rutvik@gmail.com");


        // method for derived class
        android.setDevelopersDetails("Java");

        // display Details
        android.displayDeveloperDetails();

    }
}
