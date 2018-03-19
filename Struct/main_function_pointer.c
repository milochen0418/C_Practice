#include <stdio.h>

#include <stdlib.h>
//void* bsearch(const void* key, const void*array, size_t const, size_t size, comparison_fun_t compare)
// binary search for array, which was sorted. 

//bsearch test
int cmp_op(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int values[] = { 5, 20, 29, 31, 63 };



double func1(int a) {return 0.144f;}
double func2(int a) {return 0.33f;}
double (*pf)(int); //function pointer point to a function with int parameter and return double

typedef double(*FUN)(int);


int main() {



	//function pointer test
	pf = func1;
	double ret1 = (*pf)(33);
	pf = func2;
	double ret2 = (*pf)(33);
	printf("ret1 = %f, ret2 = %f\n", ret1, ret2);
	printf("ret1 = %f, ret2 = %f\n", pf(33), pf(34));

	FUN pff1 = func1;
	FUN pff2 = func2;
	ret1 = pff1(0);
	ret2 = pff2(0);
	printf("Use typedef FUN --> \nret1 = %f, ret2 = %f\n", ret1, ret2);


	//bsearch with function pointer
	printf("\nbsearch function with function pointer\n ");
	int *item;
	int key = 31;
	// using bsearch() to find value 31 in the array 
	item = (int*) bsearch (&key, values, 5, sizeof (int), cmp_op);
	if( item != NULL ) {
		printf("Found item = %d\n", *item);
	} else {
		printf("Item = %d could not be found\n", *item);
	}

}

