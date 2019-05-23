import java.util.ArrayList;

public class Online {
	public static void main(String[] args){
		Function f = new EFunction(0.25, 1.75);

		FunctionAnalysis ana = new FunctionAnalysis();
		ana.plotTable(f, 0, 5);
		ana.plotGraph(f, 0, 5);

		for(Function g: ana.getDerivations(f, 2)){
			ana.plotTable(g, 0, 5);
			ana.plotGraph(g, 0, 5);
		}
	}
}

interface Function{
	double evaluate(double x);
	Function derivate();
}

class EFunction implements Function{
	double a, b;

	EFunction(double a, double b) {
		this.a = a;
		this.b = b;
	}

	@Override
	public double evaluate(double x) {
		return a*Math.exp(b*x);
	}

	@Override
	public Function derivate() {
		return new EFunction(a*b, b);
	}
}

class FunctionAnalysis{
	void plotTable(Function f, int a, int b){
		for(int i = a; i<=b;i++){
			System.out.println("f(" + i + "):" + f.evaluate(i));
		}
	}

	void plotGraph(Function f, int a, int b){
		for(int i = a; i<=b;i++){
			for(int j = 0;j<f.evaluate(i);j++){
				System.out.print(" ");
			}
			System.out.println("o");
		}
	}

	ArrayList<Function> getDerivations(Function f, int n) {
		ArrayList<Function> derivationlist = new ArrayList<>(n);

		Function g = f;
		for (int i = 1; i <= n; i++) {
			g = g.derivate();
			derivationlist.add(g);
		}

		return derivationlist;
	}
}
