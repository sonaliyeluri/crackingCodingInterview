#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

struct list *newNode(int data) {
	struct list *ptr = malloc(sizeof(struct list));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void deleteMiddleNode(struct list *node) {
	if (node == NULL || node->next == NULL)
		return;
	struct list *next;
	next = node->next;
	node->data = next->data;
	node->next = next->next;
	return;
}

void printList(struct list *head) {
	while (head != NULL) {
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	struct list *head;
	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	printList(head);
	deleteMiddleNode(head);
	printList(head);
	printf("\n");
	return 0;
}	
