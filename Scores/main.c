#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
假設10個人，3個科目。以rand() 給分 0~ 100
int math[10], physics[10], english[10];

(1) 求每個人自己的3科平均
(2) 求全班各科平均
(3) 求全班全科總平均
*/

//refer : http://dhcp.tcgs.tc.edu.tw/c/p005.htm

int main () { 
	srand(time(NULL));

	int math[10], physics[10], english[10];

	float student_avg[10];  // for 每個人的3科平均
	float subject_avg[3]={0,0,0}; //for 全班各科平均 
	float all_avg; // for 全班全科總平均



	int i;
	printf ("\nStudent\tMath \tPhysics\tEnglish\n");
	for (i = 0; i < 10; i++) {
		math[i] = rand() % 101;
		physics[i] = rand() % 101;
		english[i] = rand() % 101;
		printf ("%02d_th \t%3d\t%3d\t%3d\n", i+1, math[i], physics[i],english[i]);
	}
	printf("\n\n");

	printf("\nStudent personal Average\n");
	printf ("Student\tAvg\n");
	for ( i = 0 ; i < 10 ; i++) {
		student_avg[i] = (math[i] + physics[i] + english[i]);
		student_avg[i] /=3; 
		printf ("%02d_th \t%3.3f \n", i+1, student_avg[i]);
	}

	printf("\nclass subject average\n");
	printf ("Math \tPhysics\tEnglish\n");
	for ( i = 0 ; i < 10 ; i++) {
		subject_avg[0] += math[i];
		subject_avg[1] += physics[i];
		subject_avg[2] += english[i];
		
	}

	for ( i = 0; i < 3 ; i++) {
		subject_avg[i] /= 10;
		printf ("%3.3f\t", subject_avg[i]);
	}
	printf("\n");


	for ( i = 0; i < 3 ; i++) {
		all_avg += subject_avg[i];
	}
	all_avg /= 3.0f;
	printf("\nAll average subject of all student\n");
	printf("%f\n", all_avg);


	return 0;
}