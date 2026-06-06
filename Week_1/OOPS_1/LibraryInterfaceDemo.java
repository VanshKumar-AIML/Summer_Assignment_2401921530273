package OOPS_1;

// Interface
interface LibraryUser {
    void registerAccount();
    void requestBook();
}

// KidUsers class
class KidUsers implements LibraryUser {
    int age;
    String bookType;

    // constructor setter
    KidUsers(int age, String bookType) {         
        this.age = age;
        this.bookType = bookType;
    }

    @Override
    public void registerAccount() {
        if (age < 12) {
            System.out.println("You have successfully registered under a Kids Account");
        } else {
            System.out.println("Sorry, Age must be less than 12 to register as a kid");
        }
    }

    @Override
    public void requestBook() {
        if (bookType.equalsIgnoreCase("Kids")) {
            System.out.println("Book Issued successfully, please return the book within 10 days");
        } else {
            System.out.println("Oops, you are allowed to take only kids books");
        }
    }
}

// AdultUser class
class AdultUser implements LibraryUser {
    int age;
    String bookType;

    // constructor setter
    AdultUser(int age, String bookType) {
        this.age = age;
        this.bookType = bookType;
    }

    @Override
    public void registerAccount() {
        if (age > 12) {
            System.out.println("You have successfully registered under an Adult Account");
        } else {
            System.out.println("Sorry, Age must be greater than 12 to register as an adult");
        }
    }

    @Override
    public void requestBook() {
        if (bookType.equalsIgnoreCase("Fiction")) {
            System.out.println("Book Issued successfully, please return the book within 7 days");
        } else {
            System.out.println("Oops, you are allowed to take only adult Fiction books");
        }
    }
}

// Demo class
public class LibraryInterfaceDemo {
    public static void main(String[] args) {
        // Test Case 1: KidUser
        KidUsers kid1 = new KidUsers(10,"Kids");
        kid1.registerAccount();
        kid1.requestBook();

        KidUsers kid2 = new KidUsers(18,"Fiction");
        kid2.registerAccount();
        kid2.requestBook();

        // Test Case 2: AdultUser
        AdultUser adult1 = new AdultUser(5,"Kids");
        adult1.registerAccount();
        adult1.requestBook();

        AdultUser adult2 = new AdultUser(23,"Fiction");
        adult2.registerAccount();
        adult2.requestBook();
    }
}
