#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int recursion(struct list** t1, struct list *t2) {
	int result = 1;
	if (t2 != NULL) {
		result = recursion(t1, t2->next);
		if (result != 0) {
			if ((*t1)->data != t2->data)
				return 0;
			(*t1) = (*t1)->next;
		}
	}
	return result;
}

bool isPalindrome(struct list *head) {
	struct list *t1, *t2;
	t1 = head;
	t2 = head;
	int valid = 1;
	if (head != NULL) {
		if (head->next == NULL)
			return 1;
		valid = recursion(&t1, t2);
	}
	if (valid == 0)
		return 0;
	else
		return 1;
}

int main() {
	struct list *head;
	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(2);
	head->next->next->next->next = newNode(1);
	printf("%s",isPalindrome(head)?"true":"false");
	printf("\n");
	return 0;
}
