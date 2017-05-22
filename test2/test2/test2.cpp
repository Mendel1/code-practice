// test2.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include "stdafx.h"
using namespace std;
int board[10][9];
/*
	0 nothing
	1 red general
	2 red tank
	3 red horse
	4 red cannon
	5 black general
*/
/*
	black general's positon should range :
	x:from 1:3
	y:from 4:6
*/
int checkTanck(int x,int y)
{
	int block = 0;
	x--;
	y--;
	for (int i = x - 1; i >= 0; i--)
	{
		if (board[i][y] == 2)
			return 1;
		else if (board[i][y] > 0)
			break;
	}
	for (int i = x + 1; i < 10; i++)
	{
		if (board[i][y] == 2 )
			return 1;
		else if (board[i][y] > 0)
			break;
	}
	for (int i = y - 1; i >= 0; i--)
	{
		if (board[x][i] == 2 )
			return 1;
		else if (board[x][i] > 0)
			break;
	}
	for (int i = y+ 1; i <9; i++)
	{
		if (board[x][i] == 2)
			return 1;
		else if (board[x][i] > 0)
			break;
	}
}
int checkHorse(int x,int y)
{
	
}
int checkCannon(int x,int y)
{

}
int checkGeneral(int x)
{

}
int checkVictor(int bx,int by)
{
	switch (bx)
	{
	case 1:
	case 3:
		if (by == 4||by==6)
		{
			int temp = 5 - by;
			int temp1 = 2 - bx;
			if (checkTanck(bx +temp1, by) || checkHorse(bx + temp1, by) || checkCannon(bx + temp1, by) || checkGeneral(bx + temp1))
				return 0;
			if (checkGeneral(bx) || checkTanck(bx, by + temp) || checkHorse(bx, by + temp) || checkCannon(bx, by + temp))
				return 0;
			return 1;
		}
		else if (by == 5)
		{
			if (checkTanck(bx + 1, by) || checkHorse(bx + 1, by) || checkCannon(bx + 1, by) || checkGeneral(bx + 1))
				return 0;
			if (checkGeneral(bx) || checkTanck(bx, by + 1) || checkHorse(bx, by + 1) || checkCannon(bx, by + 1))
				return 0;
			if (checkGeneral(bx) || checkTanck(bx, by - 1) || checkHorse(bx, by - 1) || checkCannon(bx, by - 1))
				return 0;
			return 1;
		}
		break;
	case 2:
		if (by == 4 || by == 6)
		{
			int temp = 5 - by;
			if (checkTanck(bx + 1, by) || checkHorse(bx + 1, by) || checkCannon(bx + 1, by) || checkGeneral(bx + 1))
				return 0;
			if (checkTanck(bx- 1, by) || checkHorse(bx- 1, by) || checkCannon(bx- 1, by) || checkGeneral(bx - 1))
				return 0;
			if (checkGeneral(bx) || checkTanck(bx, by + temp) || checkHorse(bx, by + temp) || checkCannon(bx, by + temp))
				return 0;
			return 1;
		}
		else if (by == 5)
		{
			if (checkTanck(bx + 1, by) || checkHorse(bx + 1, by) || checkCannon(bx + 1, by) || checkGeneral(bx + 1))
				return 0;
			if (checkTanck(bx - 1, by) || checkHorse(bx - 1, by) || checkCannon(bx - 1, by) || checkGeneral(bx - 1))
				return 0;
			if (checkGeneral(bx) || checkTanck(bx, by + 1) || checkHorse(bx, by + 1) || checkCannon(bx, by + 1))
				return 0;
			if (checkGeneral(bx) || checkTanck(bx, by - 1) || checkHorse(bx, by - 1) || checkCannon(bx, by - 1))
				return 0;
			return 1;
		}
		break;
	default:
		break;
	}
}
void placeChess(char ch, int x, int y)
{
	switch(ch)
	{
		case 'G':board[x - 1][y - 1] = 1; break;
		case 'R':board[x - 1][y - 1] = 2; break;
		case 'H':board[x - 1][y - 1] = 3; break;
		case 'C':board[x - 1][y - 1] = 4; break;
		default:break;
	}
}
int main()
{
	//uva1399();
	//uva();
	int redleft, bk_x, bk_y;
	int x, y, i;
	char chess;
	while(cin>> redleft >> bk_x >> bk_y&&redleft&&bk_x&&bk_y)
	{
		board[bk_x - 1][bk_y - 1] = 5;
		for (i = 0; i < redleft; i++)
		{
			cin >> chess >> x >> y;
			placeChess(chess,x,y);
		}
		if (!checkVictor(bk_x, bk_y))
			cout << "YES";
		else
			cout << "NO";
	}
    return 0;
}

