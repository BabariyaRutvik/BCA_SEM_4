package Exam;

/*
  16. Implement method overriding in Java with a superclass and subclass example
 */

// super class
class OverrideDeveloper{
    void displayPlatform(){
        System.out.println("Developer works on different platforms.");
    }

}

class OverrideAndroidDeveloper extends OverrideDeveloper {
    // method overriding
    @Override
    void displayPlatform(){
        System.out.println("Android Developer works on Android platform.");
    }
}
public class MethodOverriding_16 {

    public static void main(String[] args) {
        // Creating object of superclass
        OverrideDeveloper developer = new OverrideDeveloper();
        developer.displayPlatform();

        // Creating object of subclass
        OverrideAndroidDeveloper androidDeveloper = new OverrideAndroidDeveloper();
        androidDeveloper.displayPlatform();
    }
}
