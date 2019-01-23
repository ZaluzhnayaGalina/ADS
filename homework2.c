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
/*
Для получения исходного числа операций не требуется.
n0+1 можно получить только одним способом.
Если число N=2*M, то оно в общем случае получается либо умножением M на 2, либо (N-1)+1
Отсюда S(2M)=S(M)+S(2M-1) - число способов получить половину + число способов получить предыдущее
S(2M+1)=S(2M) - получается только из предыдущего
*/
int transformOperations(int n0, int nk)
{
	if (nk>n0)
	{
	if (nk==n0+1)
		return 1;
	if (nk%2==0)
		return transformOperations(n0, nk/2)+transformOperations(n0, nk-1);
	else
		return transformOperations(n0, nk-1);
	}
	else return 1;
}
char* decTobin(int a, char* result)
{
	if (a>0)
	{
		decTobin(a/2, result);
		a%2!=0 ? strcat(result,"1") :	strcat(result,"0");
	}

}
/* int F(int n) {
    if (n > 2)
        return F(n - 1) + G(n - 2);
    else
        return n;
}

int G(int n) {
    if (n > 2)
        return G(n - 1) + F(n - 2);
    else
        return 3 - n;
}
G(6)=G(5)+F(4)=8+5=13;				F(4)=F(3)+G(2)=4+1=5;
G(5)=G(4)+F(3)=4+4=8;				F(3)=F(2)+G(1)=2+2=4;
G(4)=G(3)+F(2)=2+2=4;				F(2)=2;
G(3)=G(2)+F(1)=1+1=2;				F(1)=1;
G(2)=1;
G(1)=2;
*/

int main(int argc, char** argv)
{
	char res[256]="";
	printf("3^5 = %d\n", pow(3,5));
	printf("3^7 = %d\n", fastPow(3,7));
	decTobin(257,res);
	printf("257=%s\n",res );
	for(int i=3; i<=20; i++)
	{
		printf("Operations(%d): %d\n", i, transformOperations(3,i));
	}
	return 0;
}