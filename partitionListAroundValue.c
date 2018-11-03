#include <stdio.h>
#include <stdlib.h>

struct list{
	int data;
	struct list *next;
};

struct list *newNode(int data) {
	struct list *ptr = malloc(sizeof(struct list));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

struct list *partitionList(struct list *node, int value) {
	struct list *head;
	head = node;
	struct list *tail;
	tail = node;
	while (node != NULL) {
		struct list *next;
		next = node->next;
		if (node->data < value) {
			node->next = head;
			head = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		node = next;
	}
	tail->next = NULL;
	return node;
}

void printList(struct list *head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	struct list *head;
	head = newNode(1);
	head->next = newNode(5);
	head->next->next = newNode(6);
	head->next->next->next = newNode(7);
	head->next->next->next->next = newNode(4);
	head->next->next->next->next->next = newNode(3);
	head->next->next->next->next->next->next = newNode(2);
	printList(head);
	head = partitionList(head, 4);
	printList(head);
	printf("\n");
	return 0;
}	
