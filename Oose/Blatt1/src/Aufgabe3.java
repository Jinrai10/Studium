public class Aufgabe3 {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.println("Eingabe");
        int k = sc.nextInt();
        System.out.println(++k);
        System.out.println(k);
        System.out.println(k++);

        int k2 = 5;
        double result = k2 / 2;
        System.out.println("5 / 2 = " + result);

        boolean b = false;

        if (b = false) {
            System.out.println("b ist falsch");
        } else {
            System.out.println("b ist wahr");
        }
    }
}
