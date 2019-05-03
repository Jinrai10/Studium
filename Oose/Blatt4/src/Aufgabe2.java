public class Aufgabe2 {
    public static void main(String[] args) {
        Student student = new Student();
        Cauliflower essen1 = new Cauliflower();
        student.eat(essen1);
        Spaghetti essen2 = new Spaghetti();
        student.eat(essen2);
        Food essen = new Cauliflower();
        student.eat(essen);
    }
}


interface Food {
    public String getMeal();
}

class Cauliflower implements Food {
    public String getMeal() {
        return "Blumenkohl an Gorgonzolasoße";
    }
}

class Spaghetti implements Food {
    public String getMeal() {
        return "Spaghetti Bologneser Art";
    }
}

class Student {
    public void eat(Food food) {
        System.out.println("I like " + food.getMeal());
    }

    public void eat(Cauliflower Cauliflower) {
        System.out.println("I don’t like " + Cauliflower.getMeal());
    }
}
