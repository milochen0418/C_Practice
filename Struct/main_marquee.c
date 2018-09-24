#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SNACK_MAX_LEN 100
typedef struct MiBody {
	int row;
	int col;
} _body;

typedef struct MiSnack {
	body bodys[SNACK_MAX_LEN];
	int len;
};
typedef enum MiDir {
	UP,DOWN,LEFT,UP
};

MiSnack snack;
void snack_init();
void snack_move()

int main() {
	



}



void update_view() {

	system("clear");
	usleep(3000);
}