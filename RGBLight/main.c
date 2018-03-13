

#include <unistd.h>
#include <stdio.h>
int main() {

	int y,r,g;
	int ys=3, rs=10, gs=10;
	int state = 0;   //state= 0->y,1->r, 2->g 
	int time_cnt=0;
	int time_cnt_limit = ys;
	char light_name[10]; 

	while(1) {
		int next_state = 0;
		int next_cnt_limit = 0;
		time_cnt++;

		switch(state) {
		case 0:	//case yellow light
			sprintf(light_name,"%s","Y");
			next_state = 1;
			next_cnt_limit = rs; 
			break;
		case 1: //case red light
			sprintf(light_name,"%s","R");
			next_state = 2;
			next_cnt_limit = gs; 
			break;
		case 2: //case green light
			sprintf(light_name,"%s","G");
			next_state = 0;
			next_cnt_limit = ys; 
			break;
		default:
			break;
		}

		printf("%s : %d \n", light_name, time_cnt_limit - time_cnt + 1);
		if (time_cnt >= time_cnt_limit) {
			time_cnt = 0;
			time_cnt_limit = next_cnt_limit;
			state = next_state;
			printf("\n");
		}

		sleep(1);
	}
	return 0;
}


