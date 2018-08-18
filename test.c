```c
#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void PVE()
{
	char ChessTable[ROW][COL] = { 0 };

	printf("注意人的落子为'O',电脑落子为'*'\n");

	InitTable(ChessTable);

	MoveChess(ChessTable, 1);

}


void test()
{
	int choose;

	do
	{
		printf("*************************************\n");
		printf("*********1.PVE  2.exit  ********\n");
		printf("请输入你的选择：....\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: PVE();//人机对战
			printf("\n");
			break;
		case 2:
			break;
		default:
			printf("输入错误，请重新输入....\n");
		}
	} while (2 != choose);

}

int main()
{
	test();
	return 0;
}
```
