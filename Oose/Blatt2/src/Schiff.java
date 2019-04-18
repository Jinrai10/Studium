public class Schiff {
    private String kennzeichen;
    private String name;
    private double laenge;

    public Schiff(String name, double laenge){
        this.name = name;
        this.laenge = laenge;
    }

    public void setKennzeichen(String kennzeichen){
        this.kennzeichen = kennzeichen;
    }

    public void empfangeNachricht(String msg){
        System.out.printf("%s(%s): %s%n", this.name, this.kennzeichen, msg);
    }

    public String getName(){
        return this.name;
    }
}
