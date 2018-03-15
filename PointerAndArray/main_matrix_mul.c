/*
題目 matrix multiplication

輸入矩陣 row, column
輸入矩陣所有元素 
矩陣相乘

*/




#include <stdio.h>
#include <stdlib.h>
#define DEBUG 
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

	printf("sizeof(int*) = %lu\n", sizeof(int*));
	printf("sizeof(int) = %lu\n", sizeof(int));


	//input the size of m , n &p 
	matrix_size_input_procedure(&m,&n,&p);

	//dynamic allocate the memory space for the matrix
	A=(int*)malloc(sizeof(int)*(m*n));
	B=(int*)malloc(sizeof(int)*(n*p));
	C=(int*)malloc(sizeof(int)*(m*p));

	printf("(m,n,p) = (%d,%d,%d)\n",m,n,p );
	printf("A = %p\n", A);
	printf("&A[%d] = %p\n", m*n, &A[m*n]);
	printf("B = %p\n", B);
	printf("&B[%d] = %p\n", n*p, &B[n*p]);
	printf("C = %p\n", C);
	printf("&C[%d] = %p\n", m*p, &C[m*p]);
	printf("B-A = %ld\n", B-A);
	printf("C-B = %ld\n", C-B);

/*	int* G = ++A;
	printf("++A == G = %p\n", G);
*/

	printf("&A[0] = %p\n", &A[0]);
	printf("&A[1] = %p\n", &A[1]);


	print_matrix(3,3,A,"A");
	print_matrix(3,1,B,"B");
	//Let user to input matrix A 
	matrix_cell_input_procedure(m,n,A, "A");

	print_matrix(3,3,A,"A");
	print_matrix(3,1,B,"B");


	//Let user to input matrix B
	matrix_cell_input_procedure(n,p,B, "B");

	#ifdef DEBUG
		printf("after input_procedure() start to free B");
		free(B);
		exit(1);
	#endif			

#if 0
#ifdef DEBUG
	free(A);
	free(B);
	free(C);
	return 0;
#endif
#endif
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
				C_ij += A_ik * B_kj;
				/* The following code is just help you to debug */
				//printf("A_%d%d=%d,\tB_%d%d=%d,\tC_%d%d = %d\n",  i,k,A_ik,  k,j,B_kj,  i,j, C_ij);
			}

			matrix_set(m,p,C,i,j,C_ij);
		}
	}
	
	//print the result of matrix A
	print_matrix(m,n,A,"A");
	//print the result of matrix B
	print_matrix(n,p,B,"B");
	//print the result of matrix C
	print_matrix(m,p,C,"C");



	printf("A = %p\n", A);
	free(A); //there is some issue when release A matrix...	

	printf("B = %p\n", B);
	free(B);

	printf("C = %p\n", C);
	free(C);

	return 0;
}

void matrix_cell_input_procedure(int rows, int cols, int *matrix, char* matrix_name) {
	int i, j;

	printf("\n Matrix %s\n", matrix_name);

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			int val;
			printf("%s(%d,%d) = ", matrix_name,i,j);
			scanf("%d", &val);
			matrix_set(rows, cols, matrix, i,j, val);
			if(val == 111 && i == 2 && j == 0) {
				#ifdef DEBUG
					printf("ready to free and exit in input_procedure()");
					free(matrix);
					exit(1);
				#endif			
			}

		}
	}	 
	/*
	#ifdef DEBUG
		free(matrix);
		exit(1);
	#endif			
	*/

}

int matrix_get(int rows, int cols, int* matrix, int i, int j) {
	return matrix[i*rows + j]; 
}

void matrix_set(int rows, int cols, int* matrix, int i, int j, int val) {
	matrix[i*rows + j] = val;
#ifdef DEBUG 	
	print_matrix(rows, cols, matrix, "M");
#endif //DEBUG
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
	printf("m = "); scanf("%d", &m);
	printf("n = "); scanf("%d", &n);
	printf("p = "); scanf("%d", &p);
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

