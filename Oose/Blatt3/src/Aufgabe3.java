interface Playable {
    void song();
}

class Kassette implements Playable {

    @Override
    public void song() {
        System.out.println("Alle meine Entchen...");
    }
}

class CD implements Playable {

    @Override
    public void song() {
        System.out.println("O Tannenbaum...");
    }
}

class Stereoanlage {

    void play(Playable p) {
        p.song();
    }
}

public class Aufgabe3 {
    public static void main(String[] args) {
        Stereoanlage s = new Stereoanlage();
        Playable pl = new CD();
        s.play(pl);
        pl = new Kassette();
        s.play(pl);
    }
}
