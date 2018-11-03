#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isRotate(char *s1, char *s2) {
	int len = strlen(s1);
	char s12[2*len];
	if (len == strlen(s2) && len > 0) {
		strcpy(s12, s1);
		if (strcmp(strcat(s12,s1), s2) > 0)
			return 1;
	}
	return 0;
}

int main() {
	char s1[] = "waterbottle";
	char s2[] = "erwat";
	printf("%s",isRotate(s1, s2)?"true":"false");
	printf("\n");
	return 0;
}
