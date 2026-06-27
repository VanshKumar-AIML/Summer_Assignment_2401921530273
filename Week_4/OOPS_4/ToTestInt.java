package OOPS_4;

interface test {
    public void square() ;
}

class Arithematic implements test {
    @Override
    public void square() {
        System.out.println("Square");
    }
}

public class ToTestInt {
    public static void main(String[] args) {
        Arithematic a1 = new Arithematic();
        a1.square();
    }
}