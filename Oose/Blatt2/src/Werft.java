public class Werft {
    public Werft(){

    }

    public void produziereSchiff(String name, double laenge, Schifffahrtsamt amt){
        Schiff boot = new Schiff(name, laenge);
        boot.setKennzeichen(Schifffahrtsamt.getKennzeichen());
        amt.addSchiff(boot);

    }


}
