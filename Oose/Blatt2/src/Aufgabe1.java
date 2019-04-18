public class Aufgabe1 {
    public static void main(String[] args){
        System.out.printf("Fakultät von %s: %d%n", args[0], fak(Long.parseLong(args[0])));

        System.out.printf("Binomialkoeffizient von %s und %s: %d%n", args[1], args[2], binko(Long.parseLong(args[1]), Long.parseLong(args[2])));

        System.out.printf("Lottoproblem von %s und %s: %d%n", args[1], args[2], lotto(Long.parseLong(args[1]), Long.parseLong(args[2])));
    }

    private static long fak(long n){
        if (n <= 1) return 1;
        return n * fak(n-1);
    }

    private static long binko(long n, long k){
        if (n < k){
            return 0;
        }
        return fak(n)/(fak(k)*fak(n-k));
    }

    private static long lotto(long n, long k){
        return(binko(n, k)*fak(k));
    }

}
