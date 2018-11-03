#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

void removeDuplicates(struct list *head) {
	struct list *prev = NULL;
	int hash[MAX] = {-1};
	while (head != NULL) {
		if (hash[head->data] == 1){
			prev->next = head->next;
		}
		else {
			hash[head->data] = 1;
			prev = head;
		}
		head = head->next;
	}
}

void printList(struct list *head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	struct list *head = NULL;
	head = newNode(1);
	head->next = newNode(1);
	head->next->next = newNode(1);
	head->next->next->next = newNode(3);
	head->next->next->next->next = newNode(1);
	head->next->next->next->next->next = newNode(3);
	printList(head);
	removeDuplicates(head);
	printList(head);
	printf("\n");
	return 0;
}	
