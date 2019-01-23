#include<stdio.h>
int pow(int a, int b)
{
	if (b==0)
		return 1;
	return a*pow(a, b-1);
}
int fastPow(int a, int b)
{
	if (b==0)
		return 1;
	if (b%2==0)
		return fastPow(a*a, b/2);
	else
		return a*fastPow(a, b-1);
}
int main(int argc, char** argv)
{
	printf("3^5 = %d\n", pow(3,5));
	printf("3^7 = %d\n", fastPow(3,7));
	return 0;
}