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
//////////////////////////////////////////////
/*Problem11*/
#define MAXSIZE 20
//////////////////////////////////////////////
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
int b[2000000];
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
void test8();
void fastFactors();
void test9();
void test10();
void test11();
void test12();
void Problem11();
void Problem18();
///////////////////////////////////////////
int main()
{
	int begin = clock();
	//fastFactors();
	Problem18();
	printf("Excute time: %d ms\n",clock()-begin);
	return 0;
}
int getFactors(int n)
{
	int i;
	int count = 0;
	double q = sqrt(n);
	if (n == 1)
		return 1;
	for (i = 1; i < q; i++)
		if (n%i == 0)
			count++;
	return count * 2;
}
void fastFactors()
{
	int i, j, t, max, cnt = 0;
	max = 20000000;
	int sum = 1;
	int tmp = 0;
	int n;
	for (i = 2; i <= max; i++)
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
	j = 2;
	while (sum < 1000)
	{
		n = j*(j + 1)/2;
		sum = 1;
		for (i = 0; i < cnt&&n>1; i++)
			if (n%b[i] == 0)
			{
				tmp = 0;
				while (n&&n%b[i]==0)
				{
					tmp++;
					n /= b[i];
				}
				sum *= (tmp + 1);
			}
		j++;
	}
	printf("%d\n", j*(j-1)/2);
}
void test8()
{
	int i=0;
	int target = 1000;
	int current = 0;
	int n;
	while (current <target)
	{
		i++;
		n = i*(i + 1) / 2;
		current = getFactors(n);
	}
	printf("%d\n", n);
}
char num[52];
char sum[53];
int x,y;
void Sum(char *a, char*b, int len)
{
	int tmp = 0;
	int rest = 0; 
	for (i = len - 1; i >= 0; i--)
	{
		tmp = rest+(a[i +2] - '0') + (b[i] - '0');
		rest = tmp / 10;
		a[i + 2]=('0'+(tmp%10));
	}
	tmp=(a[1]-'0')+rest;
	a[1] = tmp % 10 + '0';
	a[0] = tmp / 10 + a[0];
}
void test9()
{
	int i, j;
	char ch = ' ';
	long tmp;
	long max = 0;
	int index;
	// read number
	int begin = clock();
	for (i = 0; i < 51; i++)
	{
		sum[i] = '0';
	}
	for (i = 0; i < 100; i++)
	{
		fgets(num, 52, stdin);
		Sum(sum, num,50);
	}

	for (i=0; i < 12; i++)
	{
		printf("%c", sum[i]);
	}
	printf("\n");
	printf("Total time: %d ms.\n", clock() - begin);
}
int ChainLenth(long long n)
{
	if (n == 1)
		return 1;
	if (n<2000000)
		if(b[n])
			return b[n];
	if (n % 2 == 0)
	{
		x = 1 + ChainLenth(n / 2);
		if(n<2000000)
			b[n]= x;
		return x;
	}
	else if (n % 2 == 1)
	{

		y=1 + ChainLenth((3 * n + 1));
		if (n<2000000)
			b[n] = y;
		return y;
	}
}
void test10()
{
	long i,tmp, flag;
	int max = 0;
	for (i = 2; i < 1000000; i++)
	{
		if(!b[i])	
			b[i] = ChainLenth(i);
		if (b[i] > max)
		{
			max = b[i];
			flag = i;
		}
	}
	printf("%d %d\n",flag, max);
}
void mul(int* num, int n)
{
	int rest, tmp,i;
	rest = 0;
	for ( i = 0;i < 400; i++)
	{
		tmp = num[i] * n + rest;
		num[i] = tmp % 10;
		rest = tmp / 10;
	}
}
void test11()
{
	int num[400] = {1,0};
	int i;
	int sum = 0;
	for (i = 0; i < 1000; i++)
		mul(num, 2);
	for (i = 0; i < 400; i++)
		sum+=num[i];
	printf("%d\n",sum);
}
void test12()
{
	int i,j, sum;
	//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 30 40 50 60 70 80 90 100 1000
	int single[29] = { 3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6,6,5,5,5,7,6,6,7,8 };
	sum = 0;
	for (j = 1; j <= 1000; j++)
	{
		i=j;
		if (i == 1000)
		{
			sum += single[0] + single[28];
			continue;
		}
		if (i >=100)
		{
			sum += (single[i / 100 - 1] + single[27]);
			i = i % 100;
			if (i)
				sum += 3;//and
			else
				continue;
		}
		if (i > 20)
		{
			sum += single[i / 10 + 17];
			i %= 10;
			if (i)
				sum += single[i - 1];
		}
		else
		{
			sum += single[i - 1];
		}
		if(j==199)
			printf("%d\n", sum);
	}
	printf("%d\n", sum);
}

void Problem11()
{
	int i, j,tmp,max;
	int grid[MAXSIZE][MAXSIZE] = { 0 };
	for (i = 0; i < MAXSIZE; i++)
	{
		if (i == 18)
			printf("18");
		for (j = 0; j < MAXSIZE; j++)
			scanf("%d", &grid[i][j]);
	}
	max = 0;
	for (i = 0; i < MAXSIZE; i++)
		for (j = 0; j < MAXSIZE - 4; j++)
		{
			tmp = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
			if (tmp > max)
				max = tmp;
			tmp = grid[j][i] * grid[j + 1][i] * grid[j + 2][i] * grid[j + 3][i];
			if (tmp > max)
				max = tmp;
		}
	for (i = 0; i<MAXSIZE - 4; i++)
		for (j = 0; j<MAXSIZE - 4; j++) {
			tmp = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
			if (tmp> max)
				max = tmp;
			tmp = grid[i][j + 3] * grid[i + 1][j + 2] * grid[i + 2][j + 1] * grid[i + 3][j];
			if (tmp > max)
				max = tmp;
		}
	printf("%d", max);
}
void Problem18()
{

}
