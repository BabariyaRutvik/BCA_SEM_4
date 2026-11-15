package Exam;

/*
  11. Create a Java program to demonstrate the use of static variables, methods, and blocks.
 */

class AppSession{
    // static variables
    static String appName;
    static int userCount;

    // static block
    static {
        appName = "App Name";
        userCount = 1;

        System.out.println("Static block executed.");
        System.out.println("Application Initialize.");
    }
    // static method
    static void  addUser(){
        userCount++;
    }

    // Static method to display information
    static void displayAppInfo() {
        System.out.println("App Name: " + appName);
        System.out.println("Total Users: " + userCount);
    }
}
public class StaticDemo_11 {
    static void main(String[] args) {
        // calling static method without calling objects
        AppSession.addUser();
        AppSession.addUser();
        AppSession.addUser();

        // Display application information
        AppSession.displayAppInfo();
    }
}
