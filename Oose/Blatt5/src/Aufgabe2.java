import java.util.ArrayList;

public class Aufgabe2 {
    public static void main(String[] args) {
        ArrayList<Koerper> koerperliste = new ArrayList<>();

        Kugel k = new Kugel(new Position(1, 1, 1), 1);
        Quader q = new Quader(new Position(2, 2, 2), 1, 1, 1);
        Quader j = new Quader(new Position(3, 3, 3), 2, 2, 2);

        koerperliste.add(k);
        koerperliste.add(q);
        koerperliste.add(j);

        for(Koerper i : koerperliste){
            i.getParameter();
        }
    }
}

class Position {
    int x;
    int y;
    int z;

    public Position(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

abstract class Koerper {
    Position p;

    public Koerper(Position p) {
        this.p = p;
    }

    public abstract void moveto(Position p);

    public abstract void scale(int a);

    public abstract double calculateVolume();

    public void getParameter() {
        System.out.println("Art: " + this.getClass().getName());
        System.out.printf("Position: (%d, %d, %d)%n", p.x, p.y, p.z);
        System.out.println("Volumen: " + this.calculateVolume());
    }
}

class Kugel extends Koerper {
    int radius;

    public Kugel(Position p, int radius) {
        super(p);
        this.radius = radius;
    }

    @Override
    public void moveto(Position p) {
        this.p = p;
    }

    @Override
    public void scale(int a) {
        radius *= a;
    }

    @Override
    public double calculateVolume() {
        return (4 / 3.) * Math.PI * Math.pow(radius, 3);
    }
}

class Quader extends Koerper {

    int laenge;
    int breite;
    int hoehe;

    public Quader(Position p, int laenge, int breite, int hoehe) {
        super(p);
        this.laenge = laenge;
        this.breite = breite;
        this.hoehe = hoehe;
    }

    @Override
    public void moveto(Position p) {
        this.p = p;
    }

    @Override
    public void scale(int a) {
        this.breite *= a;
        this.laenge *= a;
        this.hoehe *= a;

    }

    @Override
    public double calculateVolume() {
        return breite * laenge * hoehe;
    }
}

