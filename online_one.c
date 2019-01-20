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
  printf("%d\n", reverse(12345) + 1);
  printf("%d\n", power(2, 31));
  printf("%d\n", operations);
  printf("%d\n", fastPower(2, 31));
  printf("%d\n", operations);
  return 0;
}
