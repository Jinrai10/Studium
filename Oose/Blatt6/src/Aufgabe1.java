public class Aufgabe1 {
    public static void main(String[] args){
        DoubleList liste = new DoubleList(null);
        liste.add(3);
        liste.add(4);
        liste.add(0.2);
        liste.insertFirst(1);
        liste.insertFirst(0.1);
        System.out.println(liste.toString());
        liste.remove(2);
        System.out.println(liste.toString());
        liste.remove(0);
        System.out.println(liste.toString());
        liste.remove(2);
        System.out.println(liste.get(0).value);
        System.out.println(liste.toString());

    }
}

class DoubleNode{
    double value;
    DoubleNode next;

    public DoubleNode(double value, DoubleNode next) {
        this.value = value;
        this.next = next;
    }
}

class DoubleList{
    DoubleNode head;

    public DoubleList(DoubleNode head) {
        this.head = head;
    }

    public void add(double d){
        if(this.head == null){
            this.head = new DoubleNode(d, null);
        }else {
            DoubleNode node = this.head;
            while(node.next!=null){
                node = node.next;
            }
            node.next = new DoubleNode(d, null);
        }
    }

    public void insertFirst(double d){
        if(this.head == null){
            this.head = new DoubleNode(d, null);
        }else{
            this.head = new DoubleNode(d, this.head);
        }
    }

    public DoubleNode get(int i){
        DoubleNode node = this.head;
        for(int j = 0;j<i;j++){
            node = node.next;
        }
        return node;
    }

    @Override
    public String toString() {
        StringBuilder output = new StringBuilder();
        for(DoubleNode node = this.head;node!=null;node = node.next){
            output.append(node.value);
            output.append(";");
        }
        return output.toString();
    }

    public void remove(int i){
        if(this.head==null) return;

        if(i == 0){
            this.head = this.head.next;
            return;
        }

        DoubleNode node = this.head;
        for(int j = 0;j<i-1;j++){
            if(node != null)
                node = node.next;
            else return;
        }
        if(node.next != null){
            node.next = node.next.next;
        }
    }
}
