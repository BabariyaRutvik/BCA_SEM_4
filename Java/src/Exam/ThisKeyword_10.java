package Exam;


/*
 10 . Implement a Java program to demonstrate the use of this keyword.
 */
class  user{

    // instance variables
    String name;
    String email;
    int age;
    // constructor
    user(String name,String email,int age){
        // this refer to current objects
        this.name=name;
        this.email=email;
        this.age=age;
    }
    // Method to display user details
    void displayUser() {
        System.out.println("User Name: " + this.name);
        System.out.println("Email: " + this.email);
        System.out.println("Age: " + this.age);
    }
}
public class ThisKeyword_10 {

    public static void main(String[] args) {
        user user1 = new user("Rutvik", "rutvik@gmail.com", 26);
        user user2 = new user("Rahul", "rahul@gmail.com", 22);

        user1.displayUser();
        System.out.println();
        user2.displayUser();
    }
}
