```c
#ifndef __Game_h__
#define __Game_h__

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROW 3
#define COL 3

void InitTable(char chessTable[ROW][COL]);
void MoveChess(char chessTable[ROW][COL]);
void ShowTable(char chessTable[ROW][COL]);
char is_win(char chessTable[ROW][COL]);

#endif // !__Game_h__
```
