#include <stdio.h>
int main(int argc, char const *argv[])
{
	int A[]={12,23,34,45,56,67,78,89,90};
	int *P=A;
	printf("P+2=%d\n",P+2);//null
	printf("*P+2=%d\n",*P+2 );//34 non 14
	printf("*(P+2)%d\n",*(P+2) );//34
	printf("A+3=%d\n",A+3);//null
	printf("&A[7]=%d\n",&A[7]);
	printf("&A[4]-3=%d\n",&A[4]-3);
	printf("A[5]=%d\n",A[5]);
}