public class Aufgabe1 {
}

class Angestellter {
    private String vorname;
    private String nachname;
    private int alter;
    private int gehalt;

    public Angestellter(String vorname, String nachname, int alter, int gehalt) {
        this.vorname = vorname;
        this.nachname = nachname;
        this.alter = alter;
        this.gehalt = gehalt;
    }

    public String getVorname() {
        return vorname;
    }

    public String getNachname() {
        return nachname;
    }

    public int getAlter() {
        return alter;
    }

    public int getGehalt() {
        return gehalt;
    }

    public void increaseAge(){
        alter += 1;
    }

    public void increaseSalary(int value){
        gehalt += value;
    }
}

class Praktikant extends Angestellter{

    public Praktikant(String vorname, String nachname, int alter) {
        super(vorname, nachname, alter, 400);
    }

    @Override
    public void increaseSalary(int value){
        throw new UnsupportedOperationException();
    }
}

