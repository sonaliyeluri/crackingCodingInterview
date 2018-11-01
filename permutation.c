#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 256

bool permute(char *str1, char *str2) {
	int count[MAX] = {0};
	int i;
	for (i=0;str1[i]&& str2[i];i++) {
		count[str1[i]]++;
		count[str2[i]]--;
	}
	if (str1[i] || str2[i])
		return 0;
	for (i=0;i<MAX;i++)
		if (count[i])
			return 0;
	return 1;
}

int main() {
	char str1[] = "aca";
	char str2[] = "aaca";
	printf("%s",permute(str1,str2)?"true":"false");
	printf("\n");
	return 0;
}
