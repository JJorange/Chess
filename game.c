```c
#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitTable(char chessTable[ROW][COL])//初始化
{
	int row = 0;
	int col = 0;
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
			chessTable[row][col] = ' ';
	}
}

void ShowTable(char chessTable[ROW][COL])//打印棋盘
{
	int row = 0;
	int col = 0;
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			printf("%c ", chessTable[row][col]);
			if (col < COL - 1)
				printf("|");
		}
		if (row < ROW - 1)
		{
			printf("\n--|--|--\n");
		}
	}
	printf("\n");
}

void MoveChess(char chessTable[ROW][COL])
{
	int times = 0;//判断棋盘已满变量
	int player_row = 0;
	int player_col = 0;
	int computer_row = 0;
	int computer_col = 0;
	char chess_1 = '*';
	char chess_2 = 'O';

	srand((unsigned int)time(NULL));//产生随机数，让电脑落子

	for (times = 0; times <= ROW*COL / 2; times++)
	{
		printf("电脑落子...\n");//为电脑轮次
		do
		{
			computer_row = rand() % ROW;
			computer_col = rand() % COL;
		} while (chessTable[computer_row][computer_col] != ' ');
		chessTable[computer_row][computer_col] = '*';

		if (is_win(chessTable) == '*')
		{
			ShowTable(chessTable);
			printf("电脑赢了...\n");
			break;
		}
		ShowTable(chessTable);

		if (times == 4)
		{
			printf("棋盘满了...\n");
			printf("游戏结束，平局....\n");
			break;
		}

		while (1)//玩家轮次
		{
			printf("输入你想落子的坐标...\n");//人的轮次
			scanf("%d%d", &player_row, &player_col);

			if (player_row > 0 && player_row <= ROW && player_col > 0 && player_col <= COL
				&& chessTable[player_row - 1][player_col - 1] == ' ')
			{
				chessTable[player_row - 1][player_col - 1] = 'O';
				break;
			}
			else
				printf("输入有误,请重新输入...\n");
		}

		if (is_win(chessTable) == 'O')
		{
			printf("玩家落子...");
			ShowTable(chessTable);
			printf("玩家胜利...\n");
			break;
		}
		ShowTable(chessTable);
	}
}
char is_win(char chessTable[ROW][COL])//判赢函数
{
	int i = 0;
	for (i = 0; i < ROW; i++)//将每一行判断
	{
		if (chessTable[i][0] == chessTable[i][1] && chessTable[i][1] == chessTable[i][2])
			return chessTable[i][0];
	}
	for (i = 0; i < COL; i++)//将每一列进行判断
	{
		if (chessTable[0][i] == chessTable[1][i] && chessTable[1][i] == chessTable[2][i])
			return chessTable[0][i];
	}
	if ((chessTable[0][0] == chessTable[1][1] && chessTable[1][1] == chessTable[2][2])//斜线判断
		|| (chessTable[2][2] == chessTable[1][1] && chessTable[1][1] == chessTable[2][0]))
		return chessTable[1][1];
	else
		return 0;

}
```
