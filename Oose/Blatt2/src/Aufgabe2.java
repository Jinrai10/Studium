public class Aufgabe2 {
    public static void main(String[] args){
        System.out.println("(6.5f == 6.5) = " + compare(6.5, 6.5f));

        System.out.println("(6.4f == 6.4) = " + compare(6.4, 6.4f));

    }

    private static boolean compare(double a, float b){
        return a == b;
    }

}
