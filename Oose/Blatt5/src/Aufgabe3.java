import java.util.ArrayList;

public class Aufgabe3 {
    public static void main(String[] args){
        ArrayList<Double> list = new ArrayList<>();
        list.add(2.);
        list.add(1.);
        list.add(0.5);
        System.out.println(sort(list));
    }

    public static ArrayList<Double> sort(ArrayList<Double> list){
        int smallest;
        double value;
        ArrayList<Double> sortedlist = new ArrayList<>();
        for(int i = 0;i<list.size();i++){
            smallest = i;
            for(int j = i+1; j<list.size(); j++){
                if(list.get(smallest) > list.get(j)){
                    smallest = j;
                }
            }
            value = list.get(smallest);
            sortedlist.add(value);
            list.remove(smallest);
            list.add(0, value);
        }
        return sortedlist;
    }
}


