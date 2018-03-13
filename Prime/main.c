


#include <stdio.h>
int main() {
	int a,i;
	printf("prime number：\n");
	for(a=2; a<=1000; a++)
	{
		for (i=2; i<=a; i++) 
		{
			if (a % i==0 && a != i) break;
			if (i>=(a+1)/2)
			{
				printf("%d\t",a);
				break;
			}
		}
	}
	return 0;
}


