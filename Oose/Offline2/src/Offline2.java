import java.util.ArrayList;

public class Offline2 {
	static boolean istPrimzahl(int x){
		if (x == 1) return false;
		for(int i = 2; i<=x/2;i++){
			if(x%i == 0) return false;
		}
		return true;
	}

	static ArrayList<Integer> primzahlenZwischen(int anfang, int ende){
		ArrayList<Integer> primliste = new ArrayList<>();
		for(int i = anfang; i<=ende;i++){
			if (istPrimzahl(i)) primliste.add(i);
		}
		return primliste;
	}
}

class Main{
	public static void main(String[] args){
		ArrayList<Integer> primliste = Offline2.primzahlenZwischen(1,4000);
		System.out.println(primliste.toString());

		Primzahlrechner p1 = new Primzahlrechner(1, 1000);
		Primzahlrechner p2 = new Primzahlrechner(1001, 2000);
		Primzahlrechner p3 = new Primzahlrechner(2001, 3000);
		Primzahlrechner p4 = new Primzahlrechner(3001, 4000);
		p1.start();
		p2.start();
		p3.start();
		p4.start();

		try {
			p1.join();
			System.out.println(p1.getErgebnis().toString());
			p2.join();
			System.out.println(p2.getErgebnis().toString());
			p3.join();
			System.out.println(p3.getErgebnis().toString());
			p4.join();
			System.out.println(p4.getErgebnis().toString());
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}

class Primzahlrechner extends Thread{
	int ende;
	int anfang;
	private ArrayList<Integer> ergebnis = new ArrayList<>();

	public ArrayList<Integer> getErgebnis() {
		return ergebnis;
	}

	public Primzahlrechner(int anfang, int ende) {
		this.anfang = anfang;
		this.ende = ende;
	}

	@Override
	public void run(){
		this.ergebnis = Offline2.primzahlenZwischen(anfang, ende);
	}
}