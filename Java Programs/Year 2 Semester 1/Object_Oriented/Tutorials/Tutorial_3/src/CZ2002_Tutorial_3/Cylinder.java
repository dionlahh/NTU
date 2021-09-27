package CZ2002_Tutorial_3;

public class Cylinder extends Circle{

    private double height;
    private static final double PI = 3.14159;

    public Cylinder() {
        super(0,0,1.0);
        this.height = 1.0;
    }

    public Cylinder(int x, int y, double radius, double height) {
        super(x,y,radius);
        this.height = height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getHeight() {
        return height;
    }

    public double volume() {
        return super.area() * height;
    }

    public double areaC() {
        return ((super.area() * 2) + (super.getRadius() * PI * 2 * height));
    }

    public String toString() {
        return super.toString() + ", Height: " + height + ", Volume: " + this.volume() + ", Area: " + areaC();
    }
}
