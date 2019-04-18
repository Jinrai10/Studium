public class Aufgabe3 {
    public static void main(String[] args){
        System.out.printf("Größter gemeinsamer Teiler von %s und %s via Euklid: %d", args[0], args[1], euklid(Integer.parseInt(args[0]), Integer.parseInt(args[1])));
    }

    private static int euklid(int a, int b){
        if (a == 0) return b;
        else while(b != 0){
            if (a>b) a = a-b;
            else b = b-a;
        }
        return a;
    }
}
