#include<stdio.h>
#include<string.h>
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

char* decTobin(int a, char* result)
{
	if (a>0)
	{
		decTobin(a/2, result);
		a%2!=0 ? strcat(result,"1") :	strcat(result,"0");
	}

}
int main(int argc, char** argv)
{
	char res[256]="";
	printf("3^5 = %d\n", pow(3,5));
	printf("3^7 = %d\n", fastPow(3,7));
	decTobin(257,res);
	printf("257=%s",res );
	return 0;
}