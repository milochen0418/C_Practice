#include <stdio.h>
int main() {

	int x = 2; 
	for (x = 2; x <= 9; x++) {
		func99(x);
	}
}


void func99(int x) {
	int j;
	printf ("\n");
	for ( j = 1; j <= 9 ;j++) {
		printf ("%2d * %2d = %2d \t", x, j, x*j);
	}
	printf("\n");
}