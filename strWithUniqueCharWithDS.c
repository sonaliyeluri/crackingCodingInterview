#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 256

bool allUnique(char *str, int len) {
	bool hash[MAX] = {0};
	for (int i=0;i<len;i++) {
		if (hash[str[i]-'0'] == true)
			return 0;
		hash[str[i]-'0'] = 1;
	}
	return 1;
}

int main() {
	char str[] = "abcdefgh";
	printf("%s",allUnique(str,strlen(str))?"true":"false");
	printf("\n");
	return 0;
}
