#include "stdafx.h"
/*
test.c
author:mendel
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <time.h>
//////////////////////////////////////////////
/*Problem11*/
#define MAXSIZE 20
/*Problem 18*/
#define ROW 15
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
	for (i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return 0;
	return 1;
}
int max(int a, int b)
{
	return a > b ? a : b;
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
bool a1[2000001];
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

int test7()
{
	int i, j,t, max,cnt=0;
	long long sum = 0;
	max = 2000000;
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
	return cnt;
//	for (i = 0; i < cnt; i ++)
//			sum += b[i];
//	printf("%lld\n", sum);
}
void test8();
void fastFactors();
void test9();
void test10();
void test11();
void test12();
void Problem11();
int Problem18();
int Problem19();
int Problem20();
int Problem21();
int Problem22();
int Problem23();
int Problem24();
int Problem25();
int Problem26();
int Problem27();
int Problem28();
int Problem29();
int Problem30();
int Problem31();
int Problem32();
int Problem33();
int Problem34();
int Problem35();
int Problem36();
int Problem37();
int Problem38();
int Problem39();
int Problem40();
int Problem41();
int Problem42();
int Problem43();
int Problem44();
int Problem45();
int Problem46();
int Problem47();
int Problem48();
int Problem49();
int Problem50();
///////////////////////////////////////////
int main()
{
	
	//fastFactors();
	int begin1 = clock();
	int begin=Problem39();
	printf("Excute time: %d ms\n",clock()-begin1);
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
	for ( i = 0;i < 200; i++)
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
int Problem18()
{
	int i, j,begin;
	int tower[ROW][ROW] = { 0 };
	int *maxSum;
	for (i = 0; i < ROW; i++)
		for (j = 0; j <= i; j++)
			scanf("%d", &tower[i][j]);
	printf("Success to reading.\n");
	begin = clock();
	maxSum = tower[ROW-1];
	for (i = ROW - 2; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			maxSum[j] =( max(maxSum[j], maxSum[j + 1]) + tower[i][j]);
			printf("%d ", maxSum[j]);
		}
		printf("\n");
	}
	printf("%d\n", maxSum[0]);
	return begin;
}
int SundayBegin(int year,int* days)
{
	int i, sum;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
	sum = 0;
	if (year % 400 == 0)
		month[1]++;
	else if ((year % 100) &&( year % 4 == 0))
		month[1]++;
	for (i = 0; i < 12; i++)
	{
		if ((*days + 1) % 7 == 0)
		{
			sum++;
			printf("It's %4d-%02d-01\n", year, i + 1);
		}
		*days += month[i];
	}
	return sum;
}
int Problem19()
{
	int begin = clock();
	int year,sum,daysBefore;
	sum = 0;
	daysBefore=365;
	for (year = 1901; year <= 2000; year++)
	{
		sum += SundayBegin(year, &daysBefore);
	}
	printf("%d\n", sum);
	return begin;
}
int Problem20()
{
	int begin = clock();
	int num[200] = { 1 ,0};
	int sum = 0;
	for (i = 1; i < 101; i++)
	{
		mul(num, i);
	}
	for (i = 0; i < 200; i++)
		sum += num[i];
	printf("%d\n", sum);
	return begin;
}
int SumFractor(int number)
{
	int sum = 1;
	for (int i = 2; i <= sqrt(number); i++)
		if (number%i == 0)
			sum += i*i==number? i:(i + number / i);
	return sum;
}
int Problem21()
{
	int begin = clock();
	int sum = 0;
	int num[10001] = { 0 };
	for (int i = 1; i < 10001; i++)
	{
		num[i] = SumFractor(i);
	}
	for (int i = 1; i < 10001; i++)
	{
		if (num[i] < 10000 && num[num[i]]==i)
		{
			if(num[i]!=i)
			sum+=num[i];
		}
	}
	printf("%d\n", sum);
	return begin;
}
int min(int a, int b)
{
	return a > b ? b : a;
}
int comDec(const void *a, const void *b)
{
	char *str1 = (char*)a;
	char *str2 = (char*)b;
	int len = min(strlen(str1), strlen(str2));
	for (i = 0; i < len; i++)
		if (str1[i]!=str2[i])
			return str1[i]-str2[i];
	if (strlen(str1) == len)
		return -1;
	else
		return 1;
}
int ascValue(char *str)
{
	int sum = 0;
	for (int i = 0; str[i]; i++)
		sum += (str[i] - 'A' + 1);
	return sum;
}
int Problem22()
{
	char name[10000][20] = { '\0' };
	char buff;
	int i = 0;
	int j = 0;
	int beginFlag = 0;
	long long sum = 0;
	FILE* f = fopen("C:\\Users\\Mendel\\Desktop\\names.txt", "r");
	if (f == NULL)
	{
		printf("Failed to open input file.\n");
		exit(1);
	}
	while ((buff = fgetc(f)) != EOF)
	{
		if (beginFlag==0&&buff == '\"')
			beginFlag = 1;
		else if (beginFlag == 1 && buff == '\"')
		{
			beginFlag = 0;
			i++;
			j = 0;
		}
		else if (beginFlag == 1)
			name[i][j++] = buff;

	}
	qsort(name, i, sizeof(name[0]), comDec);
	for (j = 0; j < i; j++)
		sum += (j + 1)*ascValue(name[j]);
	printf("%lld", sum);
	fclose(f);
	return 0;
}
int Problem23()
{
	int begin = clock();
	long long sum = 0;
	int num[28124] = { 0 };
	int j = 0;
	int flag = 0;
	for (int i = 1; i < 28124; i++)
	{
		//tmp = SumFractor(i);
		if(SumFractor(i)>i)
			num[i] =1;
	}
	for (int i = 1; i < 28124; i++)
	{
		flag = 0;
		for (j = 12; j < i; j++)
			if (num[j] && num[i - j])
			{
				flag = 1;
				break;
			}
		if (!flag)
			sum += i;
	}
	printf("%d\n", sum);
	return begin;
}
int smallFractorial(int n)
{
	int mul=1;
	for (i = 1; i <= n; i++)
		mul *= i;
	return mul;
}
int get(int n)
{
	static int num[10] = { 0 };
	int j = 0;
	for (int i = 0; i < 10;i++)
	{
		if (!num[i])
			j++;
		if (n == j)
		{
			num[i] = 1;
			return i;
		}
	}
	return 0;
}
int Problem24()
{
	int i, j, k;
	int begin = clock();
	int target = 1000000;
	int num[10] = { 0 };
	int tmp = 0;
	j = 0;
	k = 9;
	while (j<10)
	{
		tmp= smallFractorial(k);
		for (i = 0; i < 10; i++)
		{
			target -= tmp;
			if (target <=0)
				break;
		}
		target +=tmp;
		num[j++] = get(i+1);
		k--;
	}
	for (i = 0; i < 10; i++)
		printf("%d", num[i]);
	printf("\n");
	return begin;
}
void equal(int *a, int *b)
{
	int len;
	for (len =999; len >= 0; len--)
		if (a[len] || b[len])
			break;
	for (int i = 0; i <= len; i++)
		a[i] = b[i];
}
void add(int *a, int *b)
{
	int len;
	int tmp;
	int rest = 0;
	for (len = 999; len >= 0; len--)
		if (a[len] || b[len])
			break;
	len++;
	for (int i = 0; i <= len; i++)
	{
		tmp = b[i] + a[i] + rest;
		b[i] = tmp % 10;
		rest = tmp /10;
	}
}
int Problem25()
{
	int begin = clock();
	int a[1000] = { 1,0 };
	int b[1000] = { 1,0 };
	int tmp[1000] = { 0 };
	int index = 2;
	while (!b[999])
	{
		equal(tmp, b);
		add(a, b);
		equal(a, tmp);
		index++;
	}
	printf("%d", index);
	return begin;
}
int getCycle(int n)
{
	int i,k;
	while (n % 2 == 0) n /= 2;
	while (n % 5 == 0) n /= 5;
	if (1000 % n == 0)
		return 0;
	k = 0;
	i = 1;
	do
	{
		k++;
		i = (i * 10) % n;
	} while (i != 1);
	return k;
}
int Problem26()
{
	int begin = clock();
	int tmp, index;
	int max = 0;
	for (int i = 2; i < 1000; i++)
	{
		tmp = getCycle(i);
		if (tmp > max)
		{
			max = tmp;
			index = i;
		}
	}
	printf("%d\t%d\n", index, max);
	return begin;
}
#define LEN 1000
void PrimeArray(int *a, int n)
{
	int tmp;
	int j = 0;
	bool arr[1001] = { false };
	for (int i = 2; i < 1000 && j < 200; i++)
	{
		if (!arr[i])
			a[j++] = i;
		for (int k = 0; k < j; k++)
		{
			tmp = i*a[k];
			if (tmp > LEN)
				break;
			arr[tmp] = true;
			if (i%a[k] == 0)
				break;
		}
	}
}
int Problem27()
{
	int prime[200] = { 0 };
	int begin = clock();
	int s, b,a,b_m,a_m;//s=1+a+b
	int max = 0;
	//create prime array
	PrimeArray(prime, 200);
	for (int i = 0; i < 200 && prime[i]; i++)
	{
		b = prime[i];
		for (int j = 0; j < 200 && prime[j]; j++)
		{
			a = prime[j] - prime[i] - 1;
			for (s = 0; s < 1000; s++)
				if ((s*s + a*s + b)<0||!isprime(s*s + a*s + b))
					break;
			if (s > max)
			{
				max = s;
				b_m = b;
				a_m = a;
			}
		}
	}
	printf("%d\t%d\t%d\t%d\n", max,a_m,b_m,a_m*b_m);
	return begin;
}

int Problem28()
{
	int begin = clock();
    int sum = 1;
	int a = 1;
	int b = 2;
	for (int i =0; i < 500; i++)
	{
		printf("%d\t", i + 2);
		for (int j = 0; j < 4; j++)
		{
			a += b;
			printf("%d ", a);
			sum += a;
		}
		printf("\n");
		b += 2;
	}
	printf("%d\n", sum);
	return begin;
}
int Pow(int x, int y)
{
	int res = 1;
	while (y--)
	{
		res *= x;
	}
	return res;
}
int Problem29()
{
	int tmp;
	int begin = clock();
	int num[101][101] = { 0 };
	for(int i=2;i<101;i++)
		for (int j = 2; j < 101; j++)
		{
			for(int k=2;k<=j/2&&k<(i>11?1:7);k++)
				if (j%k == 0)
				{
					tmp = Pow(i, k);
					if(tmp<101)
						num[tmp][j/k] = 1;
				}
		}
	tmp = 0;
	for (int i = 2; i < 101; i++)
	{
		for (int j = 2; j < 101; j++)
		{
			if (!num[i][j])
			{
				tmp++;
				printf("(%d,%d)\t", i, j);
			}
		}
		printf("\n");
	}
	printf("%d\n", tmp);
	return begin;
}

int Problem30()
{
	int begin = clock();
	int sum = 0;
	int tmp = 1;
	int j;
	for (int j = 2; j < 360000; j++)
	{
		tmp = 0;
		i = j;
		while (i)
		{
			tmp+=Pow( i % 10,5);
			i /= 10;
		}
		if (j == tmp)
			sum += j;
	}
	printf("%d\n", sum);
	return begin;
}

int Problem31()
{
	int begin = clock();
	int coin[8] = { 1,2,5,10,20,50,100,200 };
	int x, y, z, m, n, l, a;
	int way = 1;
	for (a = 0; a < 3; a++)
		for(l=0;l<5;l++)
			for(n=0;n<11;n++)
				for(m=0;m<21;m++)
					for(z=0;z<41;z++)
								if (200- 5 * z -10 * m -n * 20 -l * 50 -a * 100>=0)
								{
									way+=(200 - 5 * z - 10 * m - n * 20 - l * 50 - a * 100)/2+1;
								//	break;
								}
	printf("%d\n", way);
	return 0;
}
int checkArray(int *num,int len)
{
	for (int i = 0; i < len; i++)
		if (!num[i])
			return 0;
	return 1;
}
int checkNum(int n,int *num)
{
	int j = 0;
	int tmp=0;
	while (n)
	{
		if (n % 10==0)
			return 1;
		tmp = n % 10;
		if (num[tmp-1])
			return 1;
		num[tmp-1] =1;
		n /= 10;
	}
	return 0;
}
void copy(int *a, int *b,int len)
{
	for (int i = 0; i < len; i++)
		a[i] = b[i];
}
int fractor(int n, int *num)
{
	int a[9];
	for(int i=2;i*i<=n;i++)
		if (n%i == 0)
		{
			copy(a, num,9);
			if ((!checkNum(i, a)) && (!checkNum(n / i, a)))
				if (checkArray(a, 9))
				{
					printf(" |%d\t\t|%d\t\t|%-12d|\n", n, i, n / i);
					return n;
				}
		}
	return 0;
}
int Problem32()
{
	int begin = clock();
	int num[9] = { 0};
	int tmp[9] = { 0 };
	int product=0;
	printf("\n |product\t|multiplier\t|multiplicand|\n");
	printf(" |-------------------------------------------|\n");
	for (int i = 1000; i < 10000; i++)
	{
		copy(tmp, num, 9);
		if (checkNum(i,tmp))
			continue;
		product += fractor(i, tmp);
		
	}
	printf(" ---------------------------------------------\n");
	printf("Sum: %d\n", product);
	return begin;
}
int gcd(int a, int b)
{
	if (a%b == 0)
		return b;
	gcd(b, a%b);
}
int Problem33()
{
	int begin = clock();
	int numerator, denominator,a,b;
	numerator = 1;
	denominator = 1;
	for(int i=1;i<10;i++)
		for(int j=1;j<10;j++)
			for (int k = i + 1; k < 10; k++)
			{
				a = i * 10 + j;
				b = j * 10 + k;
				if (a*k == b*i)
				{
					printf("%d\t%d\n", a, b);
					numerator *= a;
					denominator *= b;
				}
			}
	denominator /= gcd(numerator, denominator);
	printf("%d\n", denominator);
	return begin;
}
int fra[10] = {1,1,2,6,24,120,720,5040,40320,362880 };
int digitSum(int n)
{
	int sum = 0;
	while (n)
	{
		sum +=fra[n % 10];
		n /= 10;
	}
	return sum;
}
//waiting for being changed.This takes 256 ms.It;s too long.
int Problem34()
{
	int begin = clock();
	long sum = 0;
	for (int i = 3; i < 2550000; i++)
		if (digitSum(i) == i)
			sum += i;
	printf("%ld\n",sum);
	return begin;
}
int CyclePrime(int n)
{
	int num[7] = { 0 };
	int tmp;
	int j = 0;
	int sum = 0;
	while (n)
	{
		num[j++] = n % 10;
		n /= 10;
	}
	for (int i = j-2; i>=0; i--)
	{
		sum = 0;
		tmp = i;
		for (int k = 0; k < j; k++)
		{
			sum *= 10;
			sum += num[tmp];
			tmp--;
			if (tmp < 0)
				tmp+=j;
		}
		if (a1[sum])
			return 0;
	}
	return 1;
}
int Problem35()
{
	int begin = clock();
	int max=test7();
	int count = 0;
	for (int i = 0; i < max; i++)
	{
		if (b[i] > 1000000)
			break;
		if (CyclePrime(b[i]))
			count++;
	}
	printf("%d\n", count);
	return begin;
}
int ishuiStr(int n)
{
	int len = 0;
	int binary[20] = { 0 };
	while (n)
	{
		binary[len++] = n % 2;
		n /= 2;
	}
	for (int i = 0; i < len / 2; i++)
	{
		if (binary[i] != binary[len - 1 - i])
			return 0;
	}
	return 1;
}
int Problem36()
{
	int begin = clock();
	int sum = 0;
	for (int i = 1; i < 1000000; i++)
	{
		if (ishui(i))
		{
			if (ishuiStr(i))
			{
				printf("%d\n", i);
				sum += i;
			}
		}
	}
	printf("%d\n", sum);
	return begin;
}

int Problem37()
{
	int begin = clock();
	int high, low;
	int count = 0;
	int sum = 0;
	int flag = 0;
	int j = 1;
	int len=test7();
	for (int i =4; i < len; i++)
	{
		flag = 0;
		j = 1;
		low = 0;
		high = 0;
		while (low < b[i])
		{
			low = b[i] % Pow(10,j++);
			if (low < 2 || a1[low])
			{
				flag = 1;
				break;
			}
		}
		high = b[i];
		while ((!flag)&&high)
		{
			if (high<2||a1[high])
			{
				flag = 1;
				break;
			}
			high /= 10;
		}
		if (!flag)
		{
			sum += b[i];
			count++;
			if (count > 11)
				break;
		}
		
	}
	printf("%d\t%d\n", sum, count);
	return begin;
}
int getdigit(int n)
{
	int len=0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return len;
}
int check(int pe, int m)
{
	int num[9] = { 0 };
	int tmp;
	for (int i = 1; i <= m; i++)
	{
		tmp = pe*i;
		while (tmp)
		{
			if (tmp % 10 == 0)
				return 0;
			num[(tmp % 10)-1] = 1;
			tmp /= 10;
		}
	}
	for (int i = 0; i < 9; i++)
		if (!num[i])
			return 0;
	return 1;
}
int Problem38()
{
	int begin = clock();
	int count;
	int tmp;
	int i;
	int j;
	for (i = 9999; i >= 1; i--)
	{
		count = 0;
		for ( j = 1; j < 10; j++)
		{
			count += getdigit(i*j);
			if (count >= 9)
				break;
		}
		if (count == 9)
		{
			if (check(i, j))
				break;
		}
	}
	printf("%d\t%ld\n", i,i*100000+i*2);
	return begin;
}
int getTriangleNum(int n)
{
	int start = n / 2;
	int end = n * 2 / 3;
	int square = n*n;
	int count = 0;
	for (int i = 1; i <= end; i++)
		for (int j = start - i; j <= end - i; j++)
			if (2 * n*(i + j) - 2 * i*j == square)
				count++;
	return count;
}
int Problem39()
{
	int max = 0;
	int index;
	int tmp;
	for (int i = 12; i < 1000; i++)
	{
		tmp = getTriangleNum(i);
		if (tmp > max)
		{
			max = tmp;
			index = i;
		}
	}
	printf("%d\t%d\n", index, max);
	return 0;
}
int getvalue(int n,int pos)
{
	while (pos)
	{
		n /= 10;
		pos++;
	}
	printf("%d\t",n%10);
	return n%10;
}
int Problem40()
{
	int begin = clock();
	int sum=1;
	int digits=0;
	int target=1;
	for (int i = 1; i < 500000; i++)
	{
		digits += getdigit(i);
		if (digits >= target)
		{
			sum *= getvalue(i,target - digits);
			target *= 10;
			if (target > 1000000)
break;
		}
	}
	printf("%d\n", sum);
	return begin;
}

int Problem41()
{
	return 0;
}
int istriangle(char * word, int len)
{
	int sum = 0;
	int n;
	for (int i = 0; i < len; i++)
		sum += (word[i] - 'A' + 1);
	sum *= 2;
	n = sqrt(sum);
	if (n*(n + 1) == sum)
		return 1;
	return 0;
}
int Problem42()
{
	int begin = clock();
	char word[20] = { '\0' };
	int j = 0;
	char buff;
	int count = 0;
	int beginFlag = 0;
	FILE* f = fopen("C:\\Users\\Mendel\\Desktop\\words.txt", "r");
	if (f == NULL)
	{
		printf("Failed to open input file.\n");
		exit(1);
	}
	while ((buff = fgetc(f)) != EOF)
	{
		if (beginFlag == 0 && buff == '\"')
			beginFlag = 1;
		else if (beginFlag == 1 && buff == '\"')
		{
			beginFlag = 0;
			if (istriangle(word, j))
				count++;
			//printf("%s\n", word);
			j = 0;
			memset(word, '\0', 20);
		}
		else if (beginFlag == 1)
			word[j++] = buff;

	}
	printf("%d\n", count);
	return begin;
}
void swap(int* a, int index1, int index2)
{
	int t = a[index1];
	a[index1] = a[index2];
	a[index2] = t;
}
long long pro_sum = 0;
int divisor[7] = { 2,3,5,7,11,13,17 };
long long tmp;
int k;
void process(int *data, int begin)
{
	if (begin >= 10)
	{
		tmp = 0;
		for ( k = 1; k < 8; k ++)
			if ((data[k] * 100 + data[k + 1] * 10 + data[k + 2])%divisor[k-1])
				break;
		if (k >= 8)
		{
			for (int j = 0; j < 10; j++)
				tmp = tmp * 10 + data[j];
			pro_sum+= tmp;
			
		}
		return;
	}
	else
	{
		for (int i = begin; i < 10; i++)
		{
			swap(data, begin, i);
			process(data, begin + 1);
			swap(data, begin, i);
		}
	}
}
//can this one be improved?
int Problem43()
{
	int begin = clock();
	int num[10] = { 1,0,2,3,4,5,6,7,8,9 };
	int tmp[10] = { 0 };
	copy(tmp, num, 10);
	process(tmp, 1);
	for (int i = 2; i < 10; i++)
	{
		swap(tmp, 0, i);
		process(tmp, 1);
		swap(tmp, 0, i);
	}
	printf("%lld\n", pro_sum);
	return clock();
}

int Problem44()
{
	int begin = clock();
	int j;
	for (int i = 0; i*(3 * i - 1)  < 100000000; i++)
	{
		a1[i*(i * 3 - 1)/2] = true;
	}
	for (int i = 1;i<3000; i++)
	{
		for ( j = 1; j < i; j++)
		{
			if (a1[i*(3 * i - 1) / 2 + j*(3 * j - 1) / 2] && a1[(i*(3 * i - 1) / 2 )- (j*(3 * j - 1) / 2)])
				break;
		}
		if (j != i)
		{
			printf("%d\n", i*(3 * i - 1) / 2- j*(3 * j - 1) / 2);
			break;
		}
	}
	return begin;
}

int Problem45()
{
	int begin = clock();
	long long  i,j,k;
	long long t;
	for (i = 287;; i+=2)
	{
		 t =i*(i + 1);
	//	printf("%d\n", i);
		k = sqrt(t / 3);
		for (j = k; j <= (k + 1); j++)
			if (j*(3 * j - 1) == t)
				break;
		if (j*(3 * j - 1) == t)
			break;
	}
	printf("%lld\t%lld\t%lld\n", i, j, t/2);
	return begin;
}
double eps = 0.0000001;
double my_abs(double x)
{
	if (x < 0)
		x = -1 * x;
	return x;
}
int nGarden(int n,int len)
{
	double tmp;
	int j = 0;
	while (j<len&&b[j++] < n);
	for (int i =j - 1; i >= 0; i--)
	{
		if ((n - b[i]) % 2)
			continue;
		tmp =sqrt( (n - b[i])/2);
		if (my_abs(tmp - (int)tmp) < eps)
			return 0;
	}
	return 1;
}
int Problem46()
{
	int begin = clock();
	int len = test7();
	int i;
	for (i = 9;; i += 2)
	{
		if (nGarden(i,len))
			break;
	}
	printf("%d\n", i);
	return begin;
}
int checkfractor(int n, int len)
{
	int count = 0;
	for (int i = 0;n>1&& i < len; i++)
	{
		if (n%b[i] == 0)
		{
			while (n%b[i] == 0)
				n /= b[i];
			count++;
		}
	}
	return count;
}
int Problem47()
{
	int len = test7();
	int num[150000] = { 0 };
	int j = 0;
	//clear up all prime number
	for (int i = 4; i < 150000; i++)
	{
		if (a1[i])
		{
			if (checkfractor(i, len)==4)
				num[j++] = i;
		}
	}
	for (int k = 0; k < j - 3; k++)
	{
		if (num[k + 1] - num[k] == 1 && num[k + 2] - num[k + 1] == 1&&num[k+3]-num[k+2]==1)
		{
			printf("%d\n", num[k]);
			break;
		}
	}
	return 0;
}
long long mod_pow(int base, int exponent)
{
	long long  sum = 1;
	while (exponent)
	{
		sum *= base;
		sum = sum % 10000000000;
		exponent--;
	}
	return sum;
}
int Problem48()
{
	int begin = clock();
	long long sum = 0;
	int i;
	for (i = 1; i < 1001; i++)
	{
		sum += mod_pow(i, i);
		sum %= 10000000000;
	}
	printf("%lld\n", sum);
	return begin;
}
int iscycle(int com, int base)
{
	int num[4] = { 0 };
	int flag[4] = { 0 };
	int j = 0;
	int tmp;
	int i;
	while (base)
	{
		num[j++] = base % 10;
		base /= 10;
	}
	while (com)
	{
		tmp = com % 10;
		for (i = 0; i < 4; i++)
		{
			if (num[i] == tmp&&flag[i]==0)
			{
				flag[i] = 1;
				break;
			}
		}
		if (i >= 4)
			return 0;
		com /= 10;
	}
	for (i = 0; i < 4; i++)
	{
		if (!flag[i])
			return 0;
	}
	return 1;
}
int Problem49()
{
	int begin = clock();
	int len = test7();
	int i = 0;
	while (b[i++] < 1000);
	for (int j = i-1; b[j] < 10000; j++)
	{
		for (int k = j + 1; b[k]< 10000; k++)
		{

			if(2 * b[k] - b[j]<10000)
				if(!a1[2*b[k]-b[j]])
					if (iscycle(b[k], b[j]) && iscycle(2 * b[k] - b[j], b[j]))
					{
						printf("%d%d%d\n", b[j],b[k], 2 * b[k] - b[j]);
				//		break;
					}
		}
			
	}
	return begin;
}

int Problem50()
{
	int begin = clock();
	int len = test7();
	int sum = 0;
	int count = 0;
	while (sum < 1000000)
	{
		if (sum + b[count] > 1000000)
			break;
		sum += b[count++];
	}
	for (int i = 0; i < count; i++)
	{
		sum -= b[i];
		if (!a1[sum])
			break;
	}
	printf("%d\t%d\n", sum, count);
	return begin;
}




