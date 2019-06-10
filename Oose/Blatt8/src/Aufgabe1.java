public class Aufgabe1 {
	public static void main(String[] args) {
		System.out.println("a)");
		//TierKaefig<Tier> kaefig = new TierKaefig<Katze>(); nicht kompilierbar
		//TierKaefig<Hund> kaefig = new TierKaefig<Tier>(); nicht kompilerbar
		//TierKaefig<?> kaefig = new TierKaefig<Katze>();
		//kaefig.setInsasse(new Katze()); // nicht kompilierbar
		TierKaefig kaefig = new TierKaefig();
		kaefig.setInsasse(new Hund());
	}
}

class TierKaefig<E> {
	private E insasse;

	public void setInsasse(E x) {
		insasse = x;
	}

	public E getInsasse() {
		return insasse;
	}
}

class Tier {
}

class Hund extends Tier {
}

class Katze extends Tier {
}
