import java.util.Objects;

public class Aufgabe2 {
    public static void main(String[] args){
        Fur schafsfell = new Fur(10);
        Fur schafsfell1 = new Fur(10);

        Sheep schaf = new Sheep("schaf", schafsfell);
        Sheep schaf1 = new Sheep("schaf1", schafsfell1);
        Sheep klon = schaf.shallowclone();
        Sheep deepklon = schaf1.deepclone();

        System.out.println(schaf.toString());
        System.out.println(klon.toString());
        System.out.println(schaf1.toString());
        System.out.println(deepklon.toString());

        klon.name = "Rex";
        klon.shear();
        deepklon.name = "Rex1";
        deepklon.shear();

        System.out.println("Klone verändert");
        System.out.println(schaf.toString());
        System.out.println(klon.toString());
        System.out.println(schaf1.toString());
        System.out.println(deepklon.toString());
    }
}

class Sheep {
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Sheep sheep = (Sheep) o;
        return Objects.equals(name, sheep.name) &&
                Objects.equals(fur, sheep.fur);
    }

    public String name;
    public Fur fur;

    public Sheep(String name, Fur fur) {
        this.name = name;
        this.fur = fur;
    }

    public Sheep deepclone(){
        return new Sheep(this.name, new Fur(this.fur.length));
    }

    public void shear() {
        fur.length = 0;
    }

    public String toString() {
        return "Name: " + name + " " + fur.toString();
    }

    public Sheep shallowclone() {
        return this;
    }
}

class Fur {
    public int length;

    public Fur(int length) {
        this.length = length;
    }

    public String toString() {
        return "Felllaenge: " + length;
    }
}