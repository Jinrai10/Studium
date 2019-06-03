import java.util.LinkedList;

public class Aufgabe3 {

	// Preorder: 10, 5, 3, 4, 7, 12, 15, 13
	// Postorder: 4, 3, 7, 5, 13, 15, 12, 10
	// Inorder: 3, 4, 5, 7, 10, 12, 13, 15
	public static void main(String[] args) {
		TNode node1, node2, node3, node4, node5, node6, node7, node8;
		node8 = new TNode(null, null, 13);
		node7 = new TNode(null, null, 4);
		node6 = new TNode(node8, null, 15);
		node5 = new TNode(null, null, 7);
		node4 = new TNode(null, node7, 3);
		node3 = new TNode(null, node6, 12);
		node2 = new TNode(node4, node5, 5);
		node1 = new TNode(node2, node3, 10);
		Tree tree = new Tree(node1);

		System.out.printf("Preorder: %n");
		tree.preorder();
		System.out.printf("%nPostorder: %n");
		tree.postorder();
		System.out.printf("%nInorder: %n");
		tree.inorder();
		System.out.printf("%nLevelorder: %n");
		tree.levelorder();
		System.out.printf("%nLevelorder: %n");
		tree.levelorder();
	}
}

class TNode {
	TNode left;
	TNode right;
	int value;

	public TNode(TNode left, TNode right, int value) {
		this.left = left;
		this.right = right;
		this.value = value;
	}
}

class Tree {
	TNode root;
	LinkedList<TNode> q = new LinkedList<TNode>();

	public Tree(TNode root) {
		this.root = root;
		q.add(root);
	}

	public void preorder() {
		if (root == null) return;
		Tree leftsubtree = new Tree(root.left);
		Tree rightsubtree = new Tree(root.right);

		System.out.printf("[%d]", root.value);

		leftsubtree.preorder();

		rightsubtree.preorder();

	}

	public void postorder() {
		if (root == null) return;
		Tree leftsubtree = new Tree(root.left);
		Tree rightsubtree = new Tree(root.right);

		leftsubtree.postorder();

		rightsubtree.postorder();

		System.out.printf("[%d]", root.value);

	}

	public void inorder() {
		if (root == null) return;
		Tree leftsubtree = new Tree(root.left);
		Tree rightsubtree = new Tree(root.right);

		leftsubtree.inorder();

		System.out.printf("[%d]", root.value);

		rightsubtree.inorder();

	}


	void levelorder(){
		if(q.isEmpty()){
			q.add(root);
			return;
		}

		TNode node = q.pop();

		System.out.printf("[%d]", node.value);

		if(node.left != null) q.add(node.left);
		if(node.right != null) q.add(node.right);

		levelorder();
	}

}
