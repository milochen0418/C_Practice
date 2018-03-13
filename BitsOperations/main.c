
/* 

HomeWork #1
1.輸入一個整數  (integer)，判斷其為奇數或偶數 
2. 將某個整數的 bit3 ~ bit 4 的值抓出來，並將其設定為11b 


HomeWork #2 

*/


//列印二進制的方法  http://www.cnblogs.com/Howe-Young/p/4160289.html 
#include <stdio.h>
#include <stdlib.h> 
void run_homework1(); 
void run_homework2();


void print_binary(int n);
void print_binary256(int n);


int main() {	
	//run_homework1();
	run_homework2();
	return 0;
}


void run_homework2() {
	int number;
	printf ("Please input number \n");
	scanf("%d", &number);

	number %= 256;

	printf ("Your number = %d \n", number );
	print_binary256(number);
	printf ("\n");

	int n = number;
	while (1) {
		print_binary256(n);
		printf("\n");
		usleep(1000*100);
		n = rotate256_left(n);
	}
}

void run_homework1() {
	int number;
	printf ("Please input number \n");
	scanf("%d", &number);

	printf ("\n input data analysis \n");
	printf ("Your number = %d \n", number );
	printf ("Hex = 0x%02X \n", number );
 	printf ("Binary = ");
 	print_binary(number);
 	printf("\n");

 	printf ("\n Solutions. \n");

	if(number % 2 ==0) {
		printf("Even Number\n");
	}
	else {
		printf("Odd Number\n");
	}

	int output_number = number ;
	
	output_number |= 0x0C;
	printf ("Output Binary = ");
 	print_binary(output_number);
 	printf("\n");	
}


void print_binary(int n)   
{   
    if(n)   
        print_binary(n/2);   
    else   
        return;   
    printf("%d",n%2);
}   

void print_binary256(int n)   
{   
	n &= 0xFF;
	int bit_iter = 0x80;
	while( (n & bit_iter) == 0 ) {
		printf("0");
		if(bit_iter <= 1) break;
		bit_iter = bit_iter >> 1;
	}
	print_binary(n);
}   

int rotate256_right (int n) {
	n = (n<<7) | (n>>1);
	//n%=256;
} 


int rotate256_left (int n) {
	n = (n<<1) | (n>>7);
	//n%=256;
} 
