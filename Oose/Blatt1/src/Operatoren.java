public class Operatoren {
    public static void main(String[] args) {
        int a = 15;
        int b = 34;
        int c = 1;
        System.out.println("1: " + (a == b)); // 15 == 34 (immer falsch)
        System.out.println("2: " + (a == b - 19)); // 15 == 34 - 19 (immer richtig)
        System.out.println("3: " + (a ^ b)); //XOR-Bitweise
        System.out.println("4: " + (a++ ^ b)); //analog zu 3 aber danach a plus eins
        System.out.println("5: " + (7 << ++c)); // 7 um c+1 nach links geshiftet (7*4 = 28)
        System.out.println("6: " + (a = b = c = 0x10)); // weisst a, b, c den Wert 16(Hexadecimalzahl) zu und gibt diesen zurück
        System.out.println("7: " + (1e1)); // 1 * 10¹
    }
}