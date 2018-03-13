/*
題目   maximum / minimum

給定一個 array, 請找出其中的最大、最小值

例 : int a[20];  以 rand 給值

void maxmin(int a[], int size, int *pmax, int *pmin)
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void maxmin(int a[], int size, int *pmax, int *pmin);
#define SIZE (20)

int main() {
	srand(time(NULL));
	int array[SIZE];
	int i;

	printf("Array values are ... \n");
	for (i = 0; i < SIZE; i++) {
		array[i] = rand() % 101;
		printf("a[%02d]=%3d \t",i, array[i]);
		if(i%5==0) printf("\n");
	}
	printf("\n\n");


	int max;
	int min;
	maxmin(array,SIZE,&max, &min);
	printf("\n max = %d, min = %d \n", max , min );
	

	return 0;
}

void maxmin(int a[], int size, int *pmax, int *pmin) {
	int i; 
	*pmax = a[0];
	*pmin = a[0];
	for ( i = 0 ; i < size; i++) {
		int val = a[i];
		if ( *pmax < val ) *pmax = val;
		if ( *pmin > val ) *pmin = val;
	}

}
