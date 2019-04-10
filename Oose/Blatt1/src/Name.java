public class Name {
    public static void main(String[] args) {
        System.out.println("Hallo " + args[0] + "!");
        System.out.println("deafult: Summe; 1: Differenz; 2: Produkt; 3: Quotient");
        int res, a = Integer.parseInt(args[1]), b = Integer.parseInt(args[2]);
        switch (Integer.parseInt(args[3])) {
            case 1:
                res = diff(a, b);
                break;
            case 2:
                res = product(a, b);
                break;
            case 3:
                res = quotient(a, b);
                break;
            default:
                res = sum(a, b);
                break;
        }
        System.out.println("Das Ergebniss der gewünschten Operation ist: " + res);
    }

    private static int sum(int a, int b) {
        return a + b;
    }

    private static int diff(int a, int b) {
        return a > b ? a - b : b - a;
    }

    private static int product(int a, int b) {
        return a * b;
    }

    private static int quotient(int a, int b) {
        try {
            return a / b;
        } catch (ArithmeticException e) {
            System.out.println("Durch 0 teilen ist illegal!");
            System.exit(0);
            return 0;
        }
    }
}
