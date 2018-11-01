#include <stdio.h>
#include <string.h>

void reverse(char *str) {
	char temp;
	int left = 0;
	int right = strlen(str) - 1;
	for (left=0;left<right;left++) {
		temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		right--;
	}
}

int main() {
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	printf("%s\n",str);
	reverse(str);
	printf("%s\n",str);
	printf("\n");
	return 0;
}
		
