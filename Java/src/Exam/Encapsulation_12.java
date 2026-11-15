package Exam;

/*
  12. Write a Java program to implement encapsulation using private variables and getter/setter methods.
 */
class User{
    // private variables
    private String name;
    private String email;
    private int age;


    // getters and setters

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
public class Encapsulation_12 {
    public static void main(String[] args) {
        // creating user objects
        User user = new User();

        // settings up s value using setters method
        user.setName("Rutvik");
        user.setEmail("rutvik@gmail.com");
        user.setAge(26);


        // gettings values using getters method
        System.out.println("----------------User Details--------------------");
        System.out.println("Name: " + user.getName());
        System.out.println("Email: " + user.getEmail());
        System.out.println("Age: " + user.getAge());
    }
}
