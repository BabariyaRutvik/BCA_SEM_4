package Exam;
/*
  42. Hospital: Write a Java program to demonstrate passing an object as a parameter by comparing the ages and bill amounts of two Patient objects.
 */
class Patient{
    private String name;
    private int age;
    private double billAmount;

    // Constructor to initialize patient details
    public Patient(String name, int age, double billAmount) {
        this.name = name;
        this.age = age;
        this.billAmount = billAmount;
    }
    // method demonstrating the passing objects
    public void compareWith(Patient other){
        System.out.println("----------- Comparison Result --------------- ");

        // comparing ages
        if (this.age > other.age){
            System.out.println(this.name + " (" + this.age + " yrs) is older then " + other.name + " (" + other.age + " yrs) is older then " + this.age + "yrs).");

        }
        else {
            System.out.println("Both patients are of the same age (" + this.age + " yrs).");
        }
        // comparing bill amount
        if (this.billAmount > other.billAmount){
            System.out.println(this.name + " has a higher bill (₹" + this.billAmount + ") than " + other.name + " (₹" + other.billAmount + ").");
        }
        else if (this.billAmount < other.billAmount){
            System.out.println(other.name + " has a higher bill (₹" + other.billAmount + ") than " + this.name + " (₹" + this.billAmount + ").");
        }
        else {
            System.out.println("Both patients have the same bill amount (₹" + this.billAmount + ").");
        }


    }
    // Method to display patient details
    public void displayDetails() {
        System.out.println("Patient Name : " + name);
        System.out.println("Age          : " + age);
        System.out.println("Bill Amount  : ₹" + billAmount);
        System.out.println("----------------------------------------");
    }
}
public class Hospital_42
{
    public static void main(String[] args) {
     Patient p1 = new Patient("John Smith", 45, 15500.00);
     Patient p2 = new Patient("Jane Doe", 32, 22000.00);

        System.out.println("----- Patient Details -----\n");
        p1.displayDetails();
        p2.displayDetails();
        // Passing object 'p2' as a parameter to compareWith() method of 'p1'
        p1.compareWith(p2);
    }
}
