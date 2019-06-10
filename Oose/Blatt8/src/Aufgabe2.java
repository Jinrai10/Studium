public class Aufgabe2 {
	public static void main(String[] args) {

	}
}

class R {
}

class E extends R {
}

class B extends R {
}

class G extends B {
}

class U {
}

class Foo {
	public static <T> T bar(T x, T y) {
		return x;
	}

	public static void main(String[] args) {
		Object o;
		R r = new R();
		E e = new E();
		B b = new B();
		G g = new G();
		U u = new U();
		R[] x;
		E[] y;
		int i = 1;
		switch(i) {
			case 1:
				r = bar(r, b);
				break;
			case 2:
				r = bar(b, r);
				break;
			case 3:
				r = bar(e, g);
				break;
			case 4:
				//e = bar(r, b); // B kann nicht zu E gecastet werden
				break;
			case 5:
				//u = bar(u, r); // u ist komplett unabhängig zu R also nicht der selbe typ
				break;
			case 6:
				o = bar(e, u);
				break;
			case 7:
				//b = bar(e, g); // E und G sind nicht miteinander verwandt da E R erweitert und G B welches auch R erweitert
				break;
			case 8:
				x = bar(new E[2], new B[4]);
				break;
			case 9:
				//y = bar(new E[4], new B[11]);
				break;
			case 10:
				o = bar(new G[8], new U[5]);
				break;
		}
	}
}
