#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
	struct tNode *left;
	struct tNode *right;
	int data;
}tNode;

int preOrder(tNode *tree) {
	if (tree != NULL) {
		printf("%i ,", tree->data);
		preOrder(tree->left);
		preOrder(tree->right);
	}
	return 1;
}

int inOrder(tNode *tree) {
	if (tree != NULL) {
		inOrder(tree->left);
		printf("%i ,", tree->data);
		inOrder(tree->right);
	}
	return 1;
}

int postOrder(tNode *tree) {
	if (tree != NULL) {
		postOrder(tree->left);
		postOrder(tree->right);
		printf("%i ,", tree->data);
	}
	return 1;
}


int main() {

	tNode *head1 = malloc(sizeof(tNode));
	tNode *head2 = malloc(sizeof(tNode));
	tNode *head3 = malloc(sizeof(tNode));
	tNode *head4 = malloc(sizeof(tNode));
	tNode *head5 = malloc(sizeof(tNode));

	head1->left = head2;
	head1->right = head3;
	head2->left = head4;
	head2->right= head5;
	head3->left = NULL;
	head3->right = NULL;
	head4->left = NULL;
	head4->right = NULL;
	head5->left = NULL;
	head5->right = NULL;

	head1->data = 1;
	head2->data = 2;
	head3->data = 3;
	head4->data = 4;
	head5->data = 5;

	printf("Preorder:\n");
	preOrder(head1);
	printf("\n");
	printf("Inorder:\n");
	inOrder(head1);
	printf("\n");
	printf("Postorder:\n");
	postOrder(head1);
	printf("\n");


}
