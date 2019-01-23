#include<stdio.h>
int pow(int a, int b)
{
	if (b==0)
		return 1;
	return a*pow(a, b-1);
}
int main(int argc, char** argv)
{
	printf("3^5 = %d", pow(3,5));
	return 0;
}