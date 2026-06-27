package OOPS_4;

class outer {
    void display() {
        System.out.println("Display Outer");
    }

    class inner {
        void display() {
            System.out.println("Display Inner");
        }
    }
}

public class _main_ {
    public static void main(String[] args) {
        new outer().display();      // display called from outer class
        new outer().new inner().display();    // display called from inner class

        /*OR done by :

        Outer outer = new Outer();
        outer.display();

        Outer.Inner inner = outer.new Inner();
        inner.display();

        */
    }
}
