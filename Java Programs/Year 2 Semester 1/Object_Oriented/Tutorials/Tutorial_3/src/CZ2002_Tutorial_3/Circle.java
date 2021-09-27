package CZ2002_Tutorial_3;

public class Circle extends Point{

    private double radius;
    private static final double PI = 3.14159; //can use Math.PI

    public Circle() {
        super(0,0);
        this.radius = 1.0;
    }

    public Circle(int x, int y, double radius) {
        super(x, y);
        this.radius = radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public double area() {
        return PI * radius * radius; //Math.PI * Math.pow(radius, 2);
    }

    public String toString() {
        return super.toString() + ", Radius: " + radius + ", Area: " + area();
    }

}
