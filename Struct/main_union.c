
#include <stdio.h>

typedef struct {
	enum tag_field {female, male } sex;
	union {
		int children;
		int beard;
	}u;
} sex_type;

typedef struct {
	int age;
	char name[10];
	float salary;
	sex_type sex_info;
} human_being;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef union {
	 u8 *p8;
	u16 *p16;
	u32 *p32;
} Pixel;

Pixel get_pixel(u8 *map, int bpp, int pos);
Pixel get_pixel(u8 *map, int bpp, int pos) {
	Pixel pixel;
	switch(bpp) {
		case 1:
			pixel.p8=(u8*)map;
			printf("pixel = %#x\n", pixel.p8[pos]);
			break;
		case 2:
			pixel.p16=(u16*)map;
			printf("pixel = %#x\n", pixel.p16[pos]);
			break;
		case 4:
			pixel.p32 = (u32*)map;
			printf("pixel = %#x\n", pixel.p32[pos]);
			break;
	}
	return pixel;
}

int main() {
	Pixel pixel;
	u8 map[]={0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
	get_pixel(map,1,2); //0x33;
	get_pixel(map,2,2); //0x55, 0x66 -> little endian reverse
	get_pixel(map,4,2); //0x99, 0xAA, 0xBB, 0xCC -> little endian reverse

	human_being persion1;
	human_being persion2;
	persion1.age = 13;
	persion1.sex_info.sex =male;
	persion1.sex_info.u.beard = 1;
	persion2.sex_info.sex =female;
	persion2.sex_info.u.children=0;


	union hold {
		int digit;
		char letter;
	}fit;

	printf("sizeof (fit) = %d\n", sizeof(fit));

	fit.digit = 0x12345678;
	printf("fit.digit = %#x\n", fit.digit);
	printf("fit.letter= %#x\n", fit.letter);

	fit.letter = 0xff;
	printf("fit.digit=%#x\n", fit.digit);

	
	return 0;
}
