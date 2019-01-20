/*
 * online_one.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 017 of year 2019 (Jan 17), 19:20
 */
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int GCD(int a, int b) {
  while (a != b) {
	if (a < b)
	  b = b - a;
	else
	  a = a - b;
  }
  return a;
}

int divGCD(int a, int b) {
  while (b != 0) {
	int t = a % b;
	a = b;
	b = t;
  }
  return a;
}

float mean(int c) {
  float average = 0;
  float sum = 0;
  int counter = 0;
  while (counter < c) {
	int in;
	scanf("%d", &in);
	sum += in;
	counter++;
  }

  if (counter != 0)
	average = sum / counter;

  return average;
}

void average() {
  int counter = 0;
  float sum = 0;
  int in;

  do {
	scanf("%d", &in);
	if (in == -1) break; // homework: get rid of this condition
	sum += in;
	counter++;
  } while (in != -1);

  if (counter != 0)
	printf("mean = %.2f\n", (float) (sum / counter));
  else
	printf("%s\n", "No input");
}
void hw_average1() {
  int counter = 0;
  float sum = 0;
  int in=0;
  while(in!=-1)
  {
	  sum+=in;
	  counter++;
	  scanf("%d",&in);
  }
  counter--;//первый раз был лишним, можно поставить counter=-1  в начале, но выглядит противоестественно;
  if (counter != 0)
	printf("mean = %.2f\n", (float) (sum / counter));
  else
	printf("%s\n", "No input");
}
void hw_average2() {
  int counter = 0;
  float sum = 0;
  int in;
  while(1)//второй вариант
  {	
	  scanf("%d",&in);
	  if (in==-1)
		  break;
	  sum+=in;
	  counter++;
  }
  if (counter != 0)
	printf("mean = %.2f\n", (float) (sum / counter));
  else
	printf("%s\n", "No input");
}
float hw_bmi(float mass_kg, float height_metres)
{
	if (height_metres!=0)
		return mass_kg/(height_metres*height_metres);
}
void swap1(int* a, int* b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}
void swap2(int *a, int *b)
{
	*a-=*b;//в a лежит a-b
	*b+=*a;//b+(a-b)=a;
	*a=*b-*a;//a-(a-b)=b;
}
int reverse(int n) {
  int t = 0;
  while (n > 0) {
	t = t * 10 + n % 10;
	n /= 10;
  }
  return t;
}
int max(int a, int b, int c, int d)
{
	return simpe_max(simpe_max(a,b),simpe_max(c,d));
}
int simpe_max(int a, int b)
{
	if (a>=b)
		return a;
	return b;
}
void quadratic_eq(float a, float b, float c, float* x1, float* x2)
{
	if (a==0)
	{
		printf("Это вообще не квадратное уравнение!");
		return;
	}
	float d = b*b-4*a*c;
	d = sqrt(d);
	*x1 = (-b+d)/(2*a);
	*x2 = (-b-d)/(2*a);
}
void season()
{
	int month;
	printf("Input number of month: ");
	scanf("%d",&month);
	if (month>=3&&month<=5)
	{
		printf("Spring\n");
	}
	else if(month>=6&&month<=8)
	{
		printf("Summer\n");
	}
	else if(month>=9&&month<=11)
	{
		printf("Autumn\n");
	}
	else printf("Winter\n");
	return;
	
	
}
void checkmate_coords()
{
	int x1,y1,x2,y2;
	printf("Input coordinates of first cell\n");
	scanf("%d",&x1);
	scanf("%d",&y1);
	printf("Input coordinates of second cell\n");
	scanf("%d",&x2);
	scanf("%d",&y2);
	if ((((x1-x2)%2==0) && ((y1-y2)%2==0))||(((x1-x2)%2!=0) && ((y1-y2)%2!=0)))
	{
		printf("Cells have the same color\n");
	}
	else
		printf("Cells' colors are different\n!");
	return;
}
int operations = 0;
int power(int base, int sign) {
  int result = 1;
  while (sign-- != 0) {
	result *= base;
	operations++;
  }
  return result;
}

int fastPower(int base, int sign) {
  int result = 1;
  operations = 0;
  while (sign != 0) {
	if (sign % 2 == 0) {
	  base *= base;
	  sign /= 2;
	} else {
	  result *= base;
	  sign--;
	}
	operations++;
  }
  return result;
}

int main(int argc, const char** argv) {
  int a=3, b=6;
  float x1,x2;
  printf("%d\n", GCD(120, 70));
  printf("%d\n", divGCD(70, 120));
  //  printf("%f\n", mean(10));
  //  average();
  hw_average1();
  hw_average2();
  
  printf("a=%d, b=%d,before swap1\n",a,b);
  swap1(&a,&b);  
  printf("a=%d, b=%d,after swap1\n",a,b);
  swap2(&a,&b);  
  printf("a=%d, b=%d,after swap2\n",a,b);
  printf("%bmi(60,1.73): %.3f\n", hw_bmi(60, 1.73));
  printf("max(2,7,8,1)=%d\n",max(2,7,8,1));
  printf("x^2-5x+6=0\n");
  quadratic_eq(1,-5,6,&x1,&x2);
  printf("x1=%f.3,x2=%f.3\n",x1,x2);
  season();
  checkmate_coords();
  printf("%d\n", reverse(12345) + 1);
  printf("%d\n", power(2, 31));
  printf("%d\n", operations);
  printf("%d\n", fastPower(2, 31));
  printf("%d\n", operations);
  return 0;
}
