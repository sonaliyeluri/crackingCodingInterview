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

struct list *kthLast(struct list *head, int k) {
	struct list *p1;
	struct list *p2;
	p1 = head;
	p2 = head;
	for (int i=0;i<k-1;i++) {
		if (p2 == NULL)
			return NULL;
		p2 = p2->next;
	}
	if (p2 == NULL)
		return NULL;
	while (p2->next != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

void printList(struct list *head) {
	while(head != NULL) {
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
	struct list *temp;
	temp = kthLast(head, 2);
	printList(temp);
	printf("\n");
	return 0;
}
