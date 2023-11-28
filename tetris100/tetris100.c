#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<stdbool.h>

clock_t startdrop, end, startground;
int x = 8, y = 0;
RECT blockSize;
int blockform;
int blockrotation = 0;
int key;
int block[7][4][4][4] = {
	{
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	{
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,1,0,0}
		}
	},
	{
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{1,0,0,0}
		}
	},
	{
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		}
	},
	{
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{1,0,0,0},
			{1,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{1,1,0,0},
			{0,0,0,0}
		}
	},
	{
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{1,0,0,0},
			{1,0,0,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{1,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		}
	},
	{
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		}
	}
};
int space[17][12] = {
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1},
};
void gotoxy(int x, int y);
void createrandomform();
bool checkcrash(int x, int y);
void dropblock();
void blocktoground();
void removeline();
void drawmap();
void drawblock();
void inputkey();
void gameover();
int main()
{
	startdrop = clock();
	createrandomform();
	while (true)
	{
		drawmap();
		drawblock();
		dropblock();
		blocktoground();
		removeline();
		inputkey();
		gameover();
	}
	return 0;
}
void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void createrandomform() 
{
	blockform = rand() % 7;
}
bool checkcrash(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockform][blockrotation][i][j] == 1) {
				int t = space[i + y][j + x / 2];
				if (t == 1 || t == 2) {
					return true;
				}
			}
		}
	}
	return false;
}
void dropblock()
{
	end = clock();
	if ((float)(end - startdrop) >= 800) {
		if (checkcrash(x, y + 1) == true) return;
		y++;
		startdrop = clock();
		startground = clock();
		system("cls");
	}
}
void blocktoground()
{
	if (checkcrash(x, y + 1) == true) {
		if ((float)(end - startground) > 1500) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (block[blockform][blockrotation][i][j] == 1) {
						space[i + y][j + x / 2] = 2;
					}
				}
			}
			x = 8;
			y = 0;
			createrandomform();
		}
	}
}
void removeline()
{
	for (int i = 16; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j < 11; j++) {
			if (space[i][j] == 2) {
				cnt++;
			}
		}
		if (cnt >= 10) {
			for (int j = 0; i - j >= 0; j++) {
				for (int x = 1; x < 11; x++) {
					if (i - j - 1 >= 0)
						space[i - j][x] = space[i - j - 1][x];
					else
						space[i - j][x] = 0;
				}
			}
		}
	}
}
void drawmap()
{
	gotoxy(0, 0);
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 12; j++) {
			if (space[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("бр");
			}
			else if (space[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("бс");
			}
		}
	}
}
void drawblock()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[blockform][blockrotation][i][j] == 1) {
				gotoxy(x + j * 2, y + i);
				printf("бс");
			}
		}
	}
}
void inputkey()
{
	if (_kbhit()) {
		key = _getch();
		switch (key) {
		case 32: 
			blockrotation++;
			if (blockrotation >= 4) blockrotation = 0;
			startground = clock();
			break;
		case 75: 
			if (checkcrash(x - 2, y) == false) {
				x -= 2;
				startground = clock();
			}
			break;
		case 77: 
			if (checkcrash(x + 2, y) == false) {
				x += 2;
				startground = clock();
			}
			break;
		case 80:
			if (checkcrash(x, y + 1) == false)
				y++;
			break;
		}
		system("cls");
	}
}
void gameover()
{
	int i,j;
	for (i = 0; i < 17; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (space[0][j] == 2)
				exit(1);
		}
	}
}
