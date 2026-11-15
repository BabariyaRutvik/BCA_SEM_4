package Exam;

/*
  14. Create a Java program to implement multilevel inheritance with constructors.

 */

class User_Multi{
    String name;

    // Constructor of User
    User_Multi(String name) {
        this.name = name;
        System.out.println("User constructor called");
    }

}
class Developer extends User_Multi{
    String language;

    // Constructor of Developer
    Developer(String name, String language) {
        super(name);
        this.language = language;
        System.out.println("Developer constructor called");
    }
}
class AndroidDeveloper extends Developer{
    String platform;

    // Constructor of AndroidDeveloper
    AndroidDeveloper(String name, String language, String platform) {
        super(name, language);
        this.platform = platform;
        System.out.println("AndroidDeveloper constructor called");
    }

    void displayDetails() {
        System.out.println("\nDeveloper Details:");
        System.out.println("Name: " + name);
        System.out.println("Language: " + language);
        System.out.println("Platform: " + platform);
    }
}
public class MultiLevelInheritance {
    static void main(String[] args) {
        // Creating object of the last derived class
        AndroidDeveloper developer =
                new AndroidDeveloper("Rutvik", "Java", "Android");

        developer.displayDetails();
    }
}
