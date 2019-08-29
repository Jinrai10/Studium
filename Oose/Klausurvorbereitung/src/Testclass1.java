public class Testclass1 {
	static int a[];
	public static void main(String[] args) {
		//A test1 = (B) new A(); //Laufzeitfehler ClassCastException
		A test2 = (A) new B();
		//B test3 = (A) new B(); //Compilierfehler
		//B test4 = (B) new A(); //Laufzeitfehler ClassCastException
		A test5 = (B) new B();
		//B test6 = (B) new A(); //Laufzeitfehler ClassCastException
		try {
			System.out.println("hello");
			a[0] = 1;
		}catch (Exception e) {
			System.out.println(e);
		}
	}
}

class A{}

class B extends A{}

