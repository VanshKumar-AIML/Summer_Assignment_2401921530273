package OOPS_4;

class Box {                     // base/super class
    double length, breadth;

    // Constructor
    public Box(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public double area() {
        return length * breadth;        // 2d area
    }
}

class Box3D extends Box {       // derived class
    double height;

    // Constructor
    public Box3D(double length, double breadth, double height) {
        super(length, breadth);         // from Box class (super/base class)
        this.height = height;           // set height
    }

    public double volume() {
        return length * breadth * height;       // 3d volume
    }
}

public class TestBox {
    public static void main(String[] args) {
        Box box = new Box(5, 4);
        System.out.println("Area of Box: " + box.area());       // 2d area

        Box3D box3d = new Box3D(5, 4, 3);
        System.out.println("Area of Box3D:" + box3d.area());    // same as 2d
        System.out.println("Volume of Box3D: " + box3d.volume());       // area * h
    }
}
