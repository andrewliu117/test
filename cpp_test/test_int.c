#include <stdio.h>

void print_matrix(int mat[][3]){
	printf("%d\n", mat[0][0]);
	printf("%d\n", mat[1][0]);
	printf("%d\n", **(mat+1));
	printf("%d\n", *(*mat+1));
}

void print_matrix1(int** mat){
	printf("%d\n", **mat);
}

void main(void){
	printf("hello world!\n");
	int mat[3][3];
	int i,j;
	for(i = 0; i < 3; i++) {
		for(j = 0; i< 3; j++){
			mat[i][j] = i * 10 + j;
		}
	}
	print_matrix(mat);
	printf("hello world!\n");
	print_matrix1((int**)mat);
}
