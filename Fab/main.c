
#include <stdio.h>

int main() {
	printf("Hello World\n");

	int i; 

	printf ("\nFabonacci:\n");
	for ( i = 0; i < 10 ; i++) {
		printf ("f(%d) = %d \t", i, fabonacci(i));
	}

	printf ("\nfactorial: n!\n");
	for ( i = 0; i < 10 ; i++) {
		printf ("f(%d) = %d \t", i, factorial(i));
	}

	printf("\n");
}

int fabonacci(unsigned int i ){ 
	if(i == 0 || i == 1) { 
		return 1; 
	}
	else {
		return fabonacci(i-2) + fabonacci(i-1);
	}
}


int factorial (unsigned int i ){
	if(i==0) {
		return 1;
	}else {
		return i*factorial(i-1);
	}
}

