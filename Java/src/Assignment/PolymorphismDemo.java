package Assignment;

import java.util.Scanner;

// Parent Class
class Shape {

    public void area() {
        System.out.println("Calculating Area...");
    }
}

// Child Class 1
class Circle extends Shape {

    double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public void area() {
        double area = 3.14 * radius * radius;
        System.out.println("Area of Circle = " + area);
    }
}

// Child Class 2
class Rectangle extends Shape {

    double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public void area() {
        double area = length * width;
        System.out.println("Area of Rectangle = " + area);
    }
}

// Main Class
public class PolymorphismDemo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Choose Shape:");
        System.out.println("1. Circle");
        System.out.println("2. Rectangle");
        System.out.print("Enter your choice: ");

        int choice = sc.nextInt();

        Shape shape;

        switch (choice) {

            case 1:
                System.out.print("Enter Radius: ");
                double radius = sc.nextDouble();

                shape = new Circle(radius);
                shape.area();
                break;

            case 2:
                System.out.print("Enter Length: ");
                double length = sc.nextDouble();

                System.out.print("Enter Width: ");
                double width = sc.nextDouble();

                shape = new Rectangle(length, width);
                shape.area();
                break;

            default:
                System.out.println("Invalid Choice!");
        }

        sc.close();
    }
}
