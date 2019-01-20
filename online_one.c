/*
 * online_one.c
 *
 * Created by Ivan I. Ovchinnikov
 * at day 017 of year 2019 (Jan 17), 19:20
 */
#include <stdio.h>
#include <stdlib.h>

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
  printf("%d\n", GCD(120, 70));
  printf("%d\n", divGCD(70, 120));
  //  printf("%f\n", mean(10));
  //  average();
  hw_average1();
  hw_average2();
  int a=3, b=6;
  printf("a=%d, b=%d,before swap1\n",a,b);
  swap1(&a,&b);  
  printf("a=%d, b=%d,after swap1\n",a,b);
  swap2(&a,&b);  
  printf("a=%d, b=%d,after swap2\n",a,b);
  printf("%bmi(60,1.73): %.3f\n", hw_bmi(60, 1.73));
  printf("%d\n", reverse(12345) + 1);
  printf("%d\n", power(2, 31));
  printf("%d\n", operations);
  printf("%d\n", fastPower(2, 31));
  printf("%d\n", operations);
  return 0;
}
