#include "stdafx.h"
#include "uva1339.h"
#include <cstring>
#define maxi 100
#define letters 26
int le[2][letters];
char input[2][maxi];
void sort(int *a, int len)
{
	int i = 0;
	int j, temp;
	for (i = 0; i < len; i++)
	{
		for(j=0;j<len-1-i;j++)
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	}
}
void uva()
{
	uva133();
}
void uva1399()
{
	int a[2][26] = { 0 };
	int i = 0;
	int j = 0;
	char str[2][100];
	while (scanf("%s %s", str[1], str[0])!=0)
	{
		if (strlen(str[0]) != strlen(str[1]))
		{
			printf("flase\n");
		}
		else
		{
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < strlen(str[0]); j++)
					a[i][str[i][j] - 'A']++;
				sort(a[i], 26);
			}
			for (i = 0; i < 26; i++)
			{
				if (a[0][i] != a[1][i])
				{
					printf("false\n");
					break;
				}
			}
			if(i==26)
				printf("true\n");
		}
	}
	
}

void uva489()
{
	int i, j;
	int cases=0;
	int failed=0;
	for (;;)
	{
		failed = 0;
		for (i = 0; i < 26; i++)
			le[0][i] = 0;
		memset(input[0], 0, maxi);
		memset(input[1], 0, maxi);
		scanf("%d", &cases);
		if (cases == -1)
			break;
		scanf("%s %s", input[0], input[1]);
		printf("Round %d:\n", cases);
		for (j = 0; j < strlen(input[0]); j++)
			le[0][input[0][j] - 'a']++;
		for (i = 0; i < strlen(input[1]); i++)
		{
			if (failed == 7)
			{
				break;
			}

			if (le[0][input[1][i]-'a'] == 0)
			{
				le[0][input[1][i]-'a'] = -1;
				failed++;
			}
			else if (le[0][input[1][i]-'a'] > 0)
			{
				le[0][input[1][i]-'a'] = -2;
			}
		}
		if(failed==7)
			printf("you failed\n");
		else if (failed < 7)
		{
			for (i = 0; i < letters; i++)
				if (le[0][i] > 0)
					break;
			if (i != 26)
				printf("you chickened out.\n");
			else
				printf("you win.\n");
		}
	}
}

void uva133()
{

}

void uva213()
{
}

void uva512()
{
}

void uva12412()
{
}

