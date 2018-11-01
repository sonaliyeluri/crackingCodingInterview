#include <stdio.h>
#include <stdbool.h>

#define R 3
#define C 4

void modifyMatrix(int mat[R][C]) {
	int row[R], col[C];
	int i, j;
	for (i=0;i<R;i++)
		row[i] = 1;

	for (i=0;i<C;i++)
		col[i] = 1;

	for (i=0;i<R;i++)
		for (j=0;j<C;j++)
			if (mat[i][j] == 0) {
				row[i] = 0;
				col[j] = 0;
			}

	for (i=0;i<R;i++)
		for (j=0;j<C;j++)
			if (row[i] == 0 || col[j] == 0)
				mat[i][j] = 0;
}

void print(int mat[R][C]) {
	for (int i=0;i<R;i++) {
		for(int j=0;j<C;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	int mat[R][C] = {{0,1,1,0},{1,1,0,1},{1,1,1,1}};
	print(mat);
	modifyMatrix(mat);
	print(mat);
	printf("\n");
	return 0;
}	
