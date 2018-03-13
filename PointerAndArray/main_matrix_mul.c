/*
題目 matrix multiplication

輸入矩陣 row, column
輸入矩陣所有元素 
矩陣相乘

*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrix_get(int rows, int cols, int* matrix, int i, int j);
//For the matrix with size = rows x cols, we get val from the (i,j) position in matrix.

void matrix_set(int rows, int cols, int* matrix, int i, int j, int val);
//For the matrix with size = rows x cols, we set val into the (i,j) position in matrix.

void matrix_set_zeros(int rows,int cols,int * matrix);
//For the matrix with size = rows x cols, we set zero in every cell.

void matrix_size_input_procedure(int *pm, int *pn, int *pp);
//The purpose is to figure matrix C = A * B
//assistant procedure to setup the size information about matrix A and matrix B

void matrix_cell_input_procedure(int rows, int cols, int *matrix, char* matrix_name);
//help you to input all cell data after you call this function

void print_matrix(int rows, int cols, int *matrix, char* matrix_name);
//print matrix data.


int main() {
	/*
		Our purpose is do C_mp = A_mn * B_np
		C is matrix with m * p size
		A is matrix with m * n size
		B is matrix with n * p size

	*/

	int m, n, p; 
	int *C;//matrix C 
	int *A;//matrix A
	int *B;//matrix B

	//input the size of m , n &p 
	matrix_size_input_procedure(&m,&n,&p);

	//dynamic allocate the memory space for the matrix
	C=(int*)malloc(sizeof(int)*(m*p));
	A=(int*)malloc(sizeof(int)*(m*n));
	B=(int*)malloc(sizeof(int)*(n*p));

	//Let user to input matrix A 
	matrix_cell_input_procedure(m,n,A, "A");

	//Let user to input matrix B
	matrix_cell_input_procedure(n,p,B, "B");
	
	//set all cell zero in matrix C.
	matrix_set_zeros(m,p,C);

	//Do the matrix multiplication : C_mp = A_mn * B_np
	int i,j,k;
	for (i=0;i<m;i++) {
		for(j=0;j<p;j++){
			int C_ij = 0;
			for(k=0;k<n;k++){
				int A_ik = matrix_get(m,n,A,i,k);
				int B_kj = matrix_get(n,p,B,k,j);
				C_ij = C_ij + A_ik * B_kj;
				/* The following code is just help you to debug */
				//printf("A_%d%d=%d,\tB_%d%d=%d,\tC_%d%d = %d\n",  i,k,A_ik,  k,j,B_kj,  i,j, C_ij);
			}

			matrix_set(m,p,C,i,j,C_ij);
		}
	}
	//print the result of matrix C
	print_matrix(m,p,C,"C");



	//release the memory space
	free(C);
	free(B);
	free(A); //there is some issue when release A matrix...

	return 0;
}

void matrix_cell_input_procedure(int rows, int cols, int *matrix, char* matrix_name) {
	int i, j;

	printf("\n Matrix %s\n", matrix_name);

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			int val;
			printf("\n%s(%d,%d) = ", matrix_name,i,j);
			scanf("%d", &val);
			matrix_set(rows, cols, matrix, i,j, val);
		}
	}	 
}

int matrix_get(int rows, int cols, int* matrix, int i, int j) {
	return matrix[i*rows + j]; 
}

void matrix_set(int rows, int cols, int* matrix, int i, int j, int val) {
	matrix[i*rows + j] = val;
}



void matrix_set_zeros(int rows, int cols, int* matrix) {
	int i;
	for(i=0;i<rows*cols;i++) {
		matrix[i] = 0;
	}
}



void matrix_size_input_procedure(int *pm, int *pn, int *pp) {
	printf("matrix multiplication : C_mp = A_mn * B_np \n");
	int m,n,p ; 
	printf("\ninput A rows m : ");
	scanf("%d", &m);
	printf("\ninput A columns n : ");
	scanf("%d", &n);
	printf("row of B = columns of A  = %d ",n );
	printf("\ninput B columns p : ");
	scanf("%d", &p);
	printf("(m,n,p) = (%d, %d, %d)\n",m,n,p );
	*pm = m;
	*pn = n;
	*pp = p;
}

void print_matrix(int rows, int cols, int *matrix, char* matrix_name) {
	printf("\nShow Matrix %s = \n", matrix_name);
	int i,j;
	for( i = 0; i<rows; i++) {
		printf("[");
		for(j = 0; j<cols; j++) {
			int val = matrix_get(rows,cols,matrix,i,j);
			printf("\t%5d", val);
		}
		printf("\t]\n");
	}
}

