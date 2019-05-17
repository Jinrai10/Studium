import java.io.*;
public class Aufgabe2 {
    public static void main(String[] args) throws IOException {
        Maincl.main(args);
    }
}


class Hamburger extends Fastfood {
    void eat(){ // kompiliert keine Fehler

    }

    //void eat() throws Exception{} does not throw Exception in Fastfood

    void eat(int y){ // kompiliert keine Fehler nicht von Fastfood abgeleitet

    }

    //void eat() throws FileNotFoundException{} //does not throw FileNotFoundException in Fastfood
    // kompiliert wirft aber keine FileNotFoundException

    //void eat() throws RuntimeException{} //does not throw RuntimeException in Fastfood
    // kompiliert kann RuntimeException werfen
}

class Fastfood {
    void eat() throws IOException {
    }
}

class Maincl {
    public static void main(String[] args) throws IOException {
        Hamburger c = new Hamburger();
        c.eat();
    }
}
