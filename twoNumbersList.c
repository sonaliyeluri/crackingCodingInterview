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

struct list *addList(struct list *l1, struct list *l2, int carry) {
	if (l1 == NULL && l2 == NULL && carry == 0)
		return NULL;
	struct list *result = malloc(sizeof(struct list));
	int value = carry;
	if(l1 != NULL)
		value += l1->data;
	if (l2 != NULL)
		value += l2->data;
	result->data = value%10;
	if (l1 != NULL || l2 != NULL) {
		result->next = addList(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, value >= 10 ? 1 : 0);
	}
	return result;
}

void printList(struct list *head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	struct list *l1;
	struct list *l2;
	l1 = newNode(6);
	l1->next = newNode(1);
	l1->next->next = newNode(7);
	l2 = newNode(2);
	l2->next = newNode(9);
	l2->next->next = newNode(5);
	printList(l1);
	printList(l2);
	struct list *res = addList(l1, l2, 0);
	printList(res);
	printf("\n");
	return 0;
}
