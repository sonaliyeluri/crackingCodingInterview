#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

void sorted(char *str, int left, int mid, int right) {
	int i , j, k, nl, nr;
	nl = mid - left + 1;
	nr = right - mid;
	char l[nl], r[nr];
	for (i=0;i<nl;i++)
		l[i] = str[left+i];
	
	for (j=0;j<nr;j++)
		r[j] = str[mid+1+j];
	i = 0;
	j = 0;
	k = left;
	while (i < nl && j < nr) {
		if (l[i] < r[j]) {
			str[k] = l[i];
			i++;
		}
		else {
			str[k] = r[j];
			j++;
		}
		k++;
	}
	while (i < nl) {
		str[k] = l[i];
		i++;
		k++;
	}
	while (j < nr) {
		str[k] = r[j];
		j++;
		k++;
	}
} 

void sort(char *str, int left, int right) {
	if (left < right) {
		int mid = left + (right - left)/2;
		sort(str, left, mid);
		sort(str, mid+1, right);
		sorted(str, left, mid, right);
	}
}

int main() {
	char str[] = "badcfehg";
	sort(str, 0, strlen(str)-1);
	for (int i=0;i<strlen(str)-1;i++){
		if (str[i] == str[i+1]) {
			printf("false\n");
			return 0;
		}
	}
	printf("true");
	printf("\n");
	return 0;
}
