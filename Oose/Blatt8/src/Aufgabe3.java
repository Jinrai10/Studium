import java.util.*;

public class Aufgabe3 {
	public static void main(String[] args){
		Stack s = new Stack();
		s.push("Apfel");
		s.push("Orange");
		System.out.println(s.pop());
		s.push("Erdbeere");
		s.push("Kiwi");
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());

		Stack si = new Stack();
		s.push(1);
		s.push(2);
		System.out.println(s.pop());
		s.push(3);
		s.push(4);
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
		System.out.println(s.pop());
	}

}

interface StackInterface extends List {
	void push(Object o);
	Object pop();
}

class Stack implements StackInterface{
	LinkedList<Object> stack = new LinkedList<>();

	@Override
	public void push(Object o) {
		stack.add(o);
	}

	@Override
	public Object pop() {
		if (stack.size()==0) return "";
		Object o = stack.get(stack.size()-1);
		stack.remove(stack.size()-1);
		return o;
	}

	@Override
	public int size() {
		return stack.size();
	}

	@Override
	public boolean isEmpty() {
		return (stack.size()==0);
	}

	@Override
	public boolean contains(Object o) {
		return stack.contains(o);
	}

	@Override
	public Iterator iterator() {
		return stack.iterator();
	}

	@Override
	public Object[] toArray() {
		return stack.toArray();
	}

	@Override
	public boolean add(Object o) {
		return stack.add(o);
	}


	@Override
	public boolean remove(Object o) {
		return stack.remove(o);
	}

	@Override
	public boolean addAll(Collection collection) {
		return false;
	}

	@Override
	public boolean addAll(int i, Collection collection) {
		return false;
	}

	@Override
	public void clear() {

	}

	@Override
	public Object get(int i) {
		return null;
	}

	@Override
	public Object set(int i, Object o) {
		return null;
	}

	@Override
	public void add(int i, Object o) {

	}

	@Override
	public Object remove(int i) {
		return null;
	}

	@Override
	public int indexOf(Object o) {
		return 0;
	}

	@Override
	public int lastIndexOf(Object o) {
		return 0;
	}

	@Override
	public ListIterator listIterator() {
		return null;
	}

	@Override
	public ListIterator listIterator(int i) {
		return null;
	}

	@Override
	public List subList(int i, int i1) {
		return null;
	}

	@Override
	public boolean retainAll(Collection collection) {
		return false;
	}

	@Override
	public boolean removeAll(Collection collection) {
		return false;
	}

	@Override
	public boolean containsAll(Collection collection) {
		return false;
	}

	@Override
	public Object[] toArray(Object[] objects) {
		return new Object[0];
	}
}
