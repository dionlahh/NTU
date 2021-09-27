package CZ2002_Tutorial_3;

public class Point {

    private int x;
    private int y;

    public Point () {
        x = 0;
        y = 0;
    }

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        String xValue = String.valueOf(x);
        String yValue = String.valueOf(y);
        return "Centre of circle: [ " + xValue + ", " + yValue + " ]";
    }

    public void setPoint(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
