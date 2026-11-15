package Exam;

/*
  15 . Write a Java program to demonstrate hierarchical inheritance with a parent and multiple child classes.
 */
// Parent class
class HierarchyDeveloper {

    String name = "Rutvik";

    void displayName() {
        System.out.println("Developer Name: " + name);
    }
}
// Child class 1
class HierarchyAndroidDeveloper extends HierarchyDeveloper {

    void developAndroidApp() {
        System.out.println("Developing Android application using Java and XML.");
    }
}
// Child class 2
class HierarchyBackendDeveloper extends HierarchyDeveloper {

    void developBackend() {
        System.out.println("Developing backend using Spring Boot.");
    }
}
public class HierarchicalInheritance {
    public static void main(String[] args) {
        // objects for Android developer
        HierarchyAndroidDeveloper androidDev = new HierarchyAndroidDeveloper();

        System.out.println("Android Developer:");
        androidDev.displayName();
        androidDev.developAndroidApp();

        System.out.println();

        // Object of BackendDeveloper
        HierarchyBackendDeveloper backendDev = new HierarchyBackendDeveloper();

        System.out.println("Backend Developer:");
        backendDev.displayName();
        backendDev.developBackend();
    }
}
