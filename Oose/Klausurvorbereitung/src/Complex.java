import static java.lang.Math.sqrt;

public class Complex {
	double imag, real;

	public Complex(double imag, double real) {
		this.imag = imag;
		this.real = real;
	}

	public Complex add(Complex ref){
		return new Complex(this.imag + ref.imag, this.real + ref.real);
	}

	public Complex multiply(Complex ref){
		return new Complex(this.imag * ref.imag - this.real*this.imag, this.real * ref.imag + this.imag*ref.real);
	}

	public double get_abs(){
		return sqrt(this.real*this.real + this.imag*this.imag);
	}

	public static boolean diverges(Complex c, int maxiter){
		Complex z0 = new Complex(0,0);
		for(int i = 0;i<maxiter;i++){
			z0 = z0.multiply(z0);
			z0 = z0.add(c);

			if(z0.get_abs() > 1000) return true;
		}
		return false;
	}

	public static void main(String[] args){
		System.out.println(diverges(new Complex(-1, -1), 10));
		diverges(new Complex(-1, 0), 10);
		diverges(new Complex(-1, 1), 10);
		diverges(new Complex(1, -1), 10);
		diverges(new Complex(1, 0), 10);
		diverges(new Complex(1, 1), 10);
	}
}



