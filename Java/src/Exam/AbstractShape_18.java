package Exam;

/*
  18. Develop a Java program to implement an abstract class Shape with subclasses Circle and Square.
 */
// Abstract parent class
abstract class GeometricFigure {
    // abstract method
    abstract void calculateArea();
}
class RoundFigure extends GeometricFigure {
    double radius = 5;

    @Override
    void calculateArea() {
        double area = Math.PI * radius * radius;
        System.out.println("Area of Circle is:" +area);
    }
}
// Square subclass
class BoxFigure extends GeometricFigure {
    double side = 4;

    @Override
    void calculateArea() {
        double area = side * side;
        System.out.println("Area of Square: " + area);
    }
}
public class AbstractShape_18
{
    static void main(String[] args) {
        RoundFigure circle = new RoundFigure();
        BoxFigure square = new BoxFigure();

        circle.calculateArea();
        square.calculateArea();
    }
}
