#include <stdio.h>
#include <math.h>
#define N 3

void rotate(int mat[N][N]) {
	int i, j;
	int temp;
	for (i=0;i<N;i++) {
		for (j=i;j<N-1-i;j++){
			temp = mat[i][j];
			mat[i][j] = mat[j][N-1-i];
			mat[j][N-1-i] = mat[N-1-i][N-1-j];
			mat[N-1-i][N-1-j] = mat[N-1-j][i];
			mat[N-1-j][i] = temp;
		}
	}
}

void print(int mat[N][N]) {
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	int mat[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
	print(mat);
	rotate(mat);
	print(mat);
	printf("\n");
	return 0;
}	
