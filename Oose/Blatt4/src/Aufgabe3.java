import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Aufgabe3 {
    public static void main(String[] args){
        Person p1 = new Person("L", "Simon", 1, "strasse", 1);
        Person p2 = new Person("M", "Simon1", 1, "strasse", 1);
        Person p3 = new Person("M", "Simon1", 2, "strasse", 1);
        Person p4 = new Person("M", "Simon1", 2, "strasse1", 1);
        Person p5 = new Person("K", "Simon", 1, "strasse", 1);
        Person[] liste = new Person[]{p1, p2, p3, p4, p5};
        for (Person i: liste)
            System.out.println(i);
        System.out.println("Minimum:");
        System.out.println(findMin(liste).toString());

        List b = Arrays.asList(liste);
        System.out.println("Minimum(Collections):");
        System.out.println(Collections.min(b));
    }

    public static Comparable findMin(Comparable[] x){
        Arrays.sort(x);
        return x[0];
    }
}

class Person implements Comparable {
    String name;
    String vorname;
    int postleitzahl;
    String strasse;
    int hausnummer;

    public Person(String name, String vorname, int postleitzahl, String strasse, int hausnummer){
        this.name = name;
        this.vorname = vorname;
        this.postleitzahl = postleitzahl;
        this.strasse = strasse;
        this.hausnummer = hausnummer;
    }

    @Override
    public int compareTo(Object o) {

        int value;
        if(0!= (value = this.name.compareTo(((Person) o).name))){
            return value;
        }

        if(0!= (value = this.vorname.compareTo(((Person) o).vorname))){
            return value;

        }

        if(0!= (value = Integer.compare(this.postleitzahl, ((Person) o).postleitzahl))){
            return value;
        }

        if(0!= (value = this.strasse.compareTo(((Person) o).strasse))){
            return value;
        }

        if(0!= (value = Integer.compare(this.hausnummer, ((Person) o).hausnummer))){
            return value;
        }

        return 0;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", vorname='" + vorname + '\'' +
                ", postleitzahl=" + postleitzahl +
                ", strasse='" + strasse + '\'' +
                ", hausnummer=" + hausnummer +
                '}';
    }
}