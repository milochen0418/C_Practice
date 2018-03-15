/*
讓使用者輸入幾個字串，或預先給定多個字串
有些長度不同 有些長度相同
char string[10][20]

找出最長與最短的字串

找出相同長度的字串 

*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN (20)
#define ARRAY_SIZE (10)

void print_string_array(void) ;
char string_array[ARRAY_SIZE][MAX_LEN] = {
	"Hello",
	"World",
	"One",
	"Two",
	"Three",
	"Four",
	"Five",
	"Six",
	"Seven",
	"Eight",
};

int len_array[ARRAY_SIZE];	


int main() {
	printf("\n");
	print_string_array();
	int i,j ;
	int min_len = MAX_LEN;
	int max_len = 0;
	for ( i = 0 ; i < ARRAY_SIZE; i++) {
		int str_len = strlen(string_array[i]);
		len_array[i] = str_len; 
		//saving string length into len_array is for beautiful future 
		if(str_len < min_len) {
			min_len = str_len;
		}
		if(str_len > max_len) {
			max_len = str_len;
		}
	} //min_len : is minimum number of string len in string_array;

	printf("\nShow the strings with minimum string size\n");
	for ( i = 0 ; i < ARRAY_SIZE; i++) {
		if(len_array[i] == min_len) {
			printf("%s\n", string_array[i]);
		}
	}

	printf("\nShow the strings with maximum string size\n");
	for ( i = 0 ; i < ARRAY_SIZE; i++) {
		if(len_array[i] == max_len) {
			printf("%s\n", string_array[i]);
		}
	}

	printf("\nShow the strings with same size\n");
	int str_len;
	for( str_len = 0; str_len < MAX_LEN ; str_len++) {
		int repeat_cnt = 0 ; //repeat_cnt with string size = j 
		int i = 0;		
		//figure out is the string size = str_len repeating ? 
		do {
			if(len_array[i++] == str_len)repeat_cnt++;
		} while(repeat_cnt < 2 && i < ARRAY_SIZE);

		if(repeat_cnt >= 2 ){ //if str_len is repeating, then
			//Use for loop to show the repeat string with size = str_len
			printf("size = %d is showing \n", str_len);
			for (i = 0 ; i < 10 ; i++) {
				if(str_len == len_array[i]) {
					printf("%s\t", string_array[i]);
				}
			}
			printf("\n");
		} 
	}

	return 0;
}

void print_string_array(void) {
	int i;
	for ( i = 0 ; i < ARRAY_SIZE; i++) {
		printf("[%d] = %s\n", i, string_array[i]);
	}
}