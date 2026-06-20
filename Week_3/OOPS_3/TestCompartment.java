package OOPS_3;

import java.util.Random;

abstract class Compartment {
    public abstract String notice();
}

class FirstClass extends Compartment {
    @Override
    public String notice() {
        return "This is a First Class compartment.";
    }
}

class Ladies extends Compartment {
    @Override
    public String notice() {
        return "This is a Ladies compartment.";
    }
}

class General extends Compartment {
    @Override
    public String notice() {
        return "This is a General compartment.";
    }
}

class Luggage extends Compartment {
    @Override
    public String notice() {
        return "This is a Luggage compartment.";
    }
}

public class TestCompartment {
    public static void main(String[] args) {
        Compartment[] compartments = new Compartment[10];
        Random rand = new Random();

        for (int i = 0; i < compartments.length; i++) {
            int choice = rand.nextInt(4) + 1; // random number between 1 and 4

            switch (choice) {
                case 1: 
                    compartments[i] = new FirstClass(); 
                    break;
                case 2: 
                    compartments[i] = new Ladies(); 
                    break;
                case 3:    
                    compartments[i] = new General(); 
                    break;
                case 4: 
                    compartments[i] = new Luggage();
                    break;
            }
        }

        // Polymorphic behavior with index labels
        for (int i = 0; i < compartments.length; i++) {
            System.out.println("Compartment #" + (i+1) + ": " + compartments[i].notice());
        }
    }
}
