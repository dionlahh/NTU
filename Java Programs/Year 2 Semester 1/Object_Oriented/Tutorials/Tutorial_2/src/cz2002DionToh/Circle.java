package cz2002DionToh;

public class Circle {

    private double radius;
    private static final double PI = 3.14159;

    // constructor
    public Circle(double radius) {
        this.radius = radius;
    }

    // default constructor
    public Circle() {
        this(1.0);
    }

    //mutator
    public void setRadius(double newRadius) {
        radius = newRadius;
    }

    //accessor
    public double getRadius() {
        return radius;
    }

    //calculate area
    public double area() {
        return PI * radius * radius;
    }

    //calc circumference
    public double circumference() {
        return 2 * PI * radius;
    }

    //print area
    public void printArea() {
        System.out.println("Area: " + PI * radius * radius);
    }

    //print circumference
    public void printCircumference() {
        System.out.println("Circumference: " + 2 * PI * radius);
    }
}
