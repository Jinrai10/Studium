public class Aufgabe4 {
    public static void main(String[] args){

    }
}

class Singleton{
    private static Singleton instance;

    private Singleton(){

    }

    public static Singleton getInstance(){
        if(instance == null) instance = new Singleton();
        return instance;
    }

}

class Singleton1 {
    private static final class InstanceHolder{
        static final Singleton1 INSTANCE = new Singleton1();
    }

    private Singleton1 (){}

    public static Singleton1 getInstance (){
        return InstanceHolder.INSTANCE;
    }
}

