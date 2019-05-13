public class Aufgabe4 {
    public static void main(String[] args){
        TestTrace.main(args);
    }
}

class CallEg{
    public void methodA() throws ArithmeticException {
        try {
            methodB();
        } catch (ArithmeticException oops) {
            oops.printStackTrace();
            throw oops;
        }
    }

    public void methodB() throws ArithmeticException {
        try {
            methodC();
        } catch (ArithmeticException oops) {
            oops.printStackTrace();
            throw oops;
        }
    }

    public void methodC() throws ArithmeticException {
        try {
            throw new ArithmeticException("/ by Zero");
        } catch (ArithmeticException oops) {
            oops.printStackTrace();
            throw oops;
        }
    }
}

class TestTrace {
    public static void main(String[] args) {
        CallEg eg = new CallEg(); // use default constructor
        try {
            eg.methodA();
        } catch (ArithmeticException oops) {
            oops.printStackTrace();
        }
    }
}