#include <stdio.h>
#include <string.h>
#define MAX 300

char *strCompress(char *str) {
	char resStr[MAX] = "";
	int count;
	char resCount;
	int i, j;
	char temp;
	for (i=0;i<strlen(str);i++) {
		temp = str[i];
		count = 1;
		for(j=i+1;j<strlen(str);j++) {
			if (temp == str[j])
				count++;
			else
				break;
		}
		resCount = count + '0';
		strcat(resStr,&temp);
		strcat(resStr,&resCount);
	}
	return resStr;
}

int main() {
	char str[] = "aabcccccaaa";
	printf("%s",strCompress(str));
	printf("\n");
	return 0;
}
