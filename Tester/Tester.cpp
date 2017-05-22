// Tester.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
/*
test.c
author:mendel
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
float Sqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x; // get bits for floating VALUE 
	i = 0x5f375a86 - (i >> 1); // gives initial guess y0
	x = *(float*)&i; // convert bits BACK to float
	x = x*(1.5f - xhalf*x*x); // Newton step, repeating increases accuracy
	return 1.0/x;
}
int isprime(int n)
{
	int i;
	for (i = 2; i < sqrt(n); i++)
		if (n%i == 0)
			return 0;
	return 1;
}
void test1()
{
	long long x = 600851475143;
	int max = 0;
	int div;
	int begin = clock();
	while (x>1)
	{
		for (div = 2; div<sqrt(x); div++)
			if (x%div == 0)
			{
				x /= div;
				if (div > max&&isprime(div))
					max = div;
				break;
			}
		if (div > sqrt(x) && isprime(x))
		{
			if (x > max)
				max = x;
			break;
		}
	}
	printf("%d\n", max);
	printf("%d ms\n", clock() - begin);
}

int ishui(int a)
{
	int i;
	int j = 0;
	i = a;
	while (i)
	{
		j = j * 10 + i % 10;
		i /= 10;
	}
	if(a==j)
		return 1;
	return 0;
}
void test2()
{
	int i;
	int base = 900;
	int max = 0;
	for (base = 999; base >= 100; base -= 1)
	{
		for (i = base; i >= 100; i--)
			if (ishui(base*i))
			{
				if (base*i > max)
					max = base*i;
			}
	}
	printf("%d\n", max);
}

int a[100];
int i = 0;
int ways;
void walk(int step, int n)
{   
	if (n <= 0)
	{
		ways++;
		printf("way %d: \n",ways);
		for (i = step - 1; i >= 0; i--)
			printf("%d ", a[i]);
		printf("\n");
	}
	if (n >= 2)
	{
		a[step] = 2;
		walk(step + 1, n - 2);
	}
	if (n > 0)
	{
		a[step] = 1;
		walk(step + 1, n - 1);
	}
}
void test3()
{
	walk(0, 12);
	printf("There is total %d methods for robot.\n", ways);
}
char str[1001];
void test4()
{
	int i ,j;
	char ch=' ';
	long tmp;
	long max=0;
	int index;
	// read number
	for (i=0; i < 1000; i++)
	{
		ch = ' ';
		while (ch == ' ' || ch == '\n')
			ch = getchar();
		str[i] = ch;
	}
	int begin = clock();
	//for (i =197; i < 210; i++)
	//{
	i = 197;
		tmp = 1;
		for (j = i; j < i + 13; j++)
		{
		//	if (str[j] == '0')
		//	{
		//		tmp = 0;
		//		i = j;
	//			break;
	//		}
			printf("%d\n", str[j] - '0');
			tmp *=( str[j] - '0');
			printf("%d\n", tmp);
		}
		if (tmp > max)
		{
			max = tmp;
			index = i;
		}
//	}
	printf("%d\n%d\n", max,index);
	printf("Excute time: %d ms\n", clock() - begin);
}
void test5()
{
	int a, b, c,tmp;
	for (c = 500; c > 0; c--)
	{
		tmp = (1000 - c)/2;
		for (a = c - 1; a > tmp; a--)
		{
			b = 1000 - a - c;
			if (b*b + a*a == c*c)
				printf("%d %d %d %d\n", a, b, c, a*b*c);
		}
	}
}
bool a1[20000001];
int b[20000000];
void test6()
{
	int i,j, max;
	long sum =2;
	max = 20000000;
	int q = sqrt(max);
	printf("begin\n");
	for (i =3; i <=q; i+=2)
	{
		if (!a1[i])
				for (j = i * 2; j <= max; j += i)
					a1[j] = true;
	}
	for (i = 3; i <= max; i+=2)
		if (!a1[i])
			sum += i;
	printf("%ld\n", sum);
}

void test7()
{
	int i, j,t, max,cnt=0;
	long long sum = 0;
	max = 20000000;
//	double q = sqrt(max);
	printf("begin\n");
	//b[cnt++] = 2;
	for (i = 2; i <= max; i ++)
	{
		if (!a1[i])
			b[cnt++] = i;
		for (j = 0; j < cnt; j++)
		{
			t = i*b[j];
			if (t > max)
				break;
			a1[t] = true;
			if (i%b[j] == 0)
				break;
		}
	}
	for (i = 0; i < cnt; i ++)
			sum += b[i];
	printf("%lld\n", sum);
}
int main()
{
	int begin = clock();
	test7();
	printf("Excute time: %d ms\n",clock()-begin);
	return 0;
}