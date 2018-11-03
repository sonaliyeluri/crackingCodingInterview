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

struct list *detectBeginning(struct list *head) {
	struct list *slow = head;
	struct list *fast = head;
	while(slow && fast && fast->next) {
		if (slow == fast)
			return slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	return fast;
}

int main() {
	struct list *head;
	head = newNode(1);
	printf("%p\n",head);
	head->next = newNode(2);
	printf("%p\n",head->next);
	head->next->next = newNode(3);
	printf("%p\n",head->next->next);
	head->next->next->next = newNode(4);
	printf("%p\n",head->next->next->next);
	head->next->next->next->next = newNode(5);
	printf("%p\n",head->next->next->next->next);
	head->next->next->next->next->next = newNode(6);
	printf("%p\n",head->next->next->next->next->next);
	head->next->next->next->next->next->next = head->next->next;
	printf("%p\n",head->next->next->next->next->next->next);
	return 0;
}	
