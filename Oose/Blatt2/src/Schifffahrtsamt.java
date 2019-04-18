public class Schifffahrtsamt {
    private Schiff[] schiffe = new Schiff[50];
    private int counter = 0;

    public Schifffahrtsamt() {

    }

    public void addSchiff(Schiff boot) {
        this.schiffe[this.counter] = boot;
        counter++;
    }

    public void meldung(String meldung, int dringlichkeit) {
        if (dringlichkeit == 1) {
            for (Schiff boot : this.schiffe) {
                if (boot != null)
                    boot.empfangeNachricht(meldung);
            }
        }
    }

    public static String getKennzeichen() {
        java.util.Random rnd = new java.util.Random();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 6; i++) {
            sb.append((char) ((rnd.nextInt(25) + 65)));
        }
        return sb.toString();
    }
}
