public class Aufgabe3 {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.println("Eingabe");
        int k = sc.nextInt();
        System.out.println(++k); // rechnet 1 auf k drauf und gibt es dann aus
        System.out.println(k); // gibt k aus
        System.out.println(k++); // gibt k aus und rechnet dann k + 1

        int k2 = 5;
        double result = k2 / 2; // Operation int geteilt durch int gibt eine Ganzzahldivision füge
        // hinter der 2 einen punkt zu oder caste einen der komponenten auf (double)
        System.out.println("5 / 2 = " + result);

        boolean b = false;

        if (b = false) { // variablen einen Wert zuweisen gibt den Wert selber zurück (hier also immer false)
            System.out.println("b ist falsch");
        } else {
            System.out.println("b ist wahr");
        }   // b ? System.out.println("b ist wahr") : System.out.println("b ist falsch"); so wäre es sinnvoll
        // b=false ? System.out.println("b ist falsch") : System.out.println("b ist wahr"); so wurde es gemacht
    }
}
