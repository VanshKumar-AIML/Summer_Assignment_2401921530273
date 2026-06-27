package OOPS_4;

class Point {
    private int x, y;      

    // Initial constructor
    public Point() {
        this.x = 0;
        this.y = 0;
    }

    // constructor setter
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // Setter Methods
    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    // set both (update)
    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // Display method for output
    public void display() {
        System.out.println("Point coordinates: (" + x + ", " + y + ")");
    }
}

public class TestPoint {
    public static void main(String[] args) {
        Point p1 = new Point();
        p1.display();       // initial -> x:0 , y:0

        Point p2 = new Point(3, 4);     // constructor setting up values (parameterized)
        p2.display();

        p2.setXY(7, 8);     // update the constructor values 
        p2.display();
    }
}

