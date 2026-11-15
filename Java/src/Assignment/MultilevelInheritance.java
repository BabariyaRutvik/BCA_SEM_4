package Assignment;

/*
  1. Develop a Java program demonstrating multilevel inheritance using a real-world example.
 */
// Grandparent Class
class App {

    public void launchApp() {
        System.out.println("Application Started");
    }
}

// Parent Class
class LoginScreen extends App {

    public void loginUser() {
        System.out.println("User Logged In Successfully");
    }
}

// Child Class
class OTPVerificationScreen extends LoginScreen {

    public void verifyOTP() {
        System.out.println("OTP Verified");
    }
}

public class MultilevelInheritance {
    public static void main(String[] args) {

        OTPVerificationScreen user = new OTPVerificationScreen();

        user.launchApp();
        user.loginUser();
        user.verifyOTP();
    }
}
