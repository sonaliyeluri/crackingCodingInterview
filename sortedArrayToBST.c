#include <stdio.h>
#include <stdlib.h>

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *newNode (int data) {
	struct tree *ptr = malloc(sizeof(struct tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

struct tree *sortedArrayToBST(int a[], int start, int end) {
	if (start > end)
		return NULL;
	int mid = start + (end - start)/2;
	struct tree *root = newNode(a[mid]);
	root->left = sortedArrayToBST(a, start, mid-1);
	root->right = sortedArrayToBST(a, mid+1, end);
	return root;
}

void inOrder(struct tree *root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(a)/sizeof(a[0]);
	struct tree *root = sortedArrayToBST(a, 0, n-1);
	inOrder(root);
	printf("\n");
	return 0;
}
