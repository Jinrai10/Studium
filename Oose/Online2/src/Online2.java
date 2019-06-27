import java.util.ArrayList;

class Online2 {
	private static boolean istPrimzahl(int x){
		if (x == 1) return false;
		for(int i = 2; i<=x/2;i++){
			if(x%i == 0) return false;
		}
		return true;
	}

	static ArrayList<Integer> primzahlenZwischen(int anfang, int ende){
		ArrayList<Integer> liste = new ArrayList<>();
		for(int i = anfang; i<=ende; i++){
			if (istPrimzahl(i)) liste.add(i);
		}
		return liste;
	}
}

class Main{
	public static void main(String[] args){
		ArrayList<Integer> primliste = Online2.primzahlenZwischen(1, 4000);
		System.out.println(primliste.toString() + "\n");
		long starttime;

		Primzahlrechner p1 = new Primzahlrechner(1, 1000);
		Primzahlrechner p2 = new Primzahlrechner(1001, 2000);
		Primzahlrechner p3 = new Primzahlrechner(2001, 3000);
		Primzahlrechner p4 = new Primzahlrechner(3001, 4000);

		starttime = System.currentTimeMillis();
		p1.start();
		p2.start();
		p3.start();
		p4.start();


		try {
			p1.join();
			System.out.println("Time spent for 1-1000: " + (System.currentTimeMillis() - starttime));
			System.out.println(p1.getErgebnis().toString() + "\n");

			p2.join();
			System.out.println("Time spent for 1001-2000: " + (System.currentTimeMillis() - starttime));
			System.out.println(p2.getErgebnis().toString() + "\n");

			p3.join();
			System.out.println("Time spent for 2001-3000: " + (System.currentTimeMillis() - starttime));
			System.out.println(p3.getErgebnis().toString() + "\n");

			p4.join();
			System.out.println("Time spent for 3001-4000: " + (System.currentTimeMillis() - starttime));
			System.out.println(p4.getErgebnis().toString() + "\n");
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

	}
}

class Primzahlrechner extends Thread{
	private ArrayList<Integer> ergebnis;
	private int anfang;
	private int ende;

	Primzahlrechner(int anfang, int ende) {
		this.anfang = anfang;
		this.ende = ende;
	}

	ArrayList<Integer> getErgebnis() {
		return ergebnis;
	}

	@Override
	public void run(){
		ergebnis = Online2.primzahlenZwischen(anfang, ende);
	}
}
