import java.util.Scanner;

public class Aufgabe3 {
    public static void main(String[] args) throws NumberTooBigException, NumberTooSmallException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Gib Zahl 5 ein: ");
        int i = scanner.nextInt();
        if(i > 5) throw new NumberTooBigException(String.format("Das ist nicht die Zahl 5, denn %d > 5", i));
        if(i < 5) throw new NumberTooSmallException(String.format("Das ist nicht die Zahl 5, denn %d < 5", i));

    }
}

class NumberTooBigException extends RuntimeException {
    public NumberTooBigException(String message) {
        super(message);
    }
}

class NumberTooSmallException extends Exception {
    public NumberTooSmallException(String message) {
        super(message);
    }
}


