public class Generics {
	public static void main(String[] haltsmaul){
		Node a = new Node<Integer>(1, null);
		Node b = new Node<Double>(1., a);
		int [][][] c = {{{1}}};
		System.out.println(m(c));
	}

	public static long m(int [][][] a){
		long sum = 0;
		for(int[][] i : a){
			for(int[] j : i){
				for(int k: j){
					sum+=k;
				}
			}
		}
		return sum;
	}
}



class Node<T>{
	T data;
	Node next;

	public Node(T a, Node n){
		data = a;
		next = n;
	}
	public T getData(T d){return data;}
	public void setData(T d){ data = d; }
	public void setNext(Node n){ next = n; }
	public Node getNext(){ return next; }
}

class List{
	private Node head;

	public List() {
		head = null;
	}
}
