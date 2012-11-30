#include <stdio.h>

void print_matrix(char mat[][3]){
	printf("%c\n", mat[0][0]);
	printf("%c\n", mat[1][0]);
	printf("%c\n", **(mat+1));
	printf("%c\n", *(*mat+1));
}

void print_matrix1(char** mat){
	printf("%s\n", *mat);
}

void main(void){
	printf("hello world!\n");
	char mat[3][3];
	int i,j;
	for(i = 0; i < 3; i++) {
		for(j = 0; i< 3; j++){
			mat[i][j] = (char)('a' + i * 3 + j);
		}
	}
	mat[2][2] = 0;
	printf("%c\n", **(mat+1));
	printf("%c\n", *(*mat+1));
	
	printf("calling!\n");

	print_matrix(mat);
	printf("hello world!\n");
	print_matrix1((char**)mat);
}
