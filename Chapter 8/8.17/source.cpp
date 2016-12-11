#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void mazeTraverse(char maze[12][12], int startPointX, int startPointY, string direction, bool isTheFirstStep);
void print(char maze[12][12], int startPointX, int startPointY, string direction);
void mazeGenerator(char maze[12][12], int& startPointX, int& startPointY);

int main()
{
	char maze[12][12];
	int startPointX, startPointY;
	mazeGenerator(maze, startPointX, startPointY);
	mazeTraverse(maze, startPointX, startPointY, "", true);
	system("pause");
	return 0;
}



void mazeTraverse(char maze[12][12], int startPointX, int startPointY, string direction, bool isTheFirstStep)
{
	print(maze, startPointX, startPointY, direction);
	if ((!isTheFirstStep) && (startPointY == 11 || startPointX == 11 || startPointX == 0 || startPointY == 0))
	{
		return;
	}
	if (direction == "")
	{
		if (startPointX + 1 < 12 && maze[startPointX + 1][startPointY] == '.')
		{
			mazeTraverse(maze, startPointX + 1, startPointY, "down", false);
		}
		else if (startPointX - 1 >= 0 && maze[startPointX - 1][startPointY] == '.')
		{
			mazeTraverse(maze, startPointX - 1, startPointY, "up", false);
		}
		else if (startPointY - 1 >= 0 && maze[startPointX][startPointY - 1] == '.')
		{
			mazeTraverse(maze, startPointX, startPointY - 1, "left", false);
		}
		else if (startPointY + 1 >= 0 && maze[startPointX][startPointY + 1] == '.')
		{
			mazeTraverse(maze, startPointX, startPointY + 1, "right", false);
		}
	}
	else
	{
		if (direction == "right")
		{
			if (maze[startPointX + 1][startPointY] == '#' && maze[startPointX][startPointY + 1] == '.')
			{
				mazeTraverse(maze, startPointX, startPointY + 1, "right", false);
			}
			if (maze[startPointX + 1][startPointY] == '#' && maze[startPointX][startPointY + 1] == '#' && maze[startPointX - 1][startPointY] == '.')
			{
				mazeTraverse(maze, startPointX, startPointY, "up", false);
			}
			if (maze[startPointX + 1][startPointY] == '#' && maze[startPointX][startPointY + 1] == '#' && maze[startPointX - 1][startPointY] == '#')
			{
				mazeTraverse(maze, startPointX, startPointY, "left", false);
			}
			if (maze[startPointX + 1][startPointY] == '.')
			{
				mazeTraverse(maze, startPointX + 1, startPointY, "down", false);
			}
		}
		if (direction == "left")
		{
			if (maze[startPointX - 1][startPointY] == '#' && maze[startPointX][startPointY - 1] == '.')
			{
				mazeTraverse(maze, startPointX, startPointY - 1, "left", false);
			}
			if (maze[startPointX - 1][startPointY] == '#' && maze[startPointX][startPointY - 1] == '#' && maze[startPointX + 1][startPointY] == '.')
			{
				mazeTraverse(maze, startPointX, startPointY, "down", false);
			}
			if (maze[startPointX - 1][startPointY] == '#' && maze[startPointX][startPointY - 1] == '#' && maze[startPointX + 1][startPointY] == '#')
			{
				mazeTraverse(maze, startPointX, startPointY, "right", false);
			}
			if (maze[startPointX - 1][startPointY] == '.')
			{
				mazeTraverse(maze, startPointX - 1, startPointY, "up", false);
			}
		}
		if (direction == "up")
		{
			if (maze[startPointX][startPointY + 1] == '#' && maze[startPointX - 1][startPointY] == '.')
			{
				mazeTraverse(maze, startPointX - 1, startPointY, "up", false);
			}
			if (maze[startPointX][startPointY + 1] == '#' && maze[startPointX - 1][startPointY] == '#' && maze[startPointX][startPointY - 1] == '.')
			{
				mazeTraverse(maze, startPointX, startPointY, "left", false);
			}
			if (maze[startPointX][startPointY + 1] == '#' && maze[startPointX - 1][startPointY] == '#' && maze[startPointX][startPointY - 1] == '#')
			{
				mazeTraverse(maze, startPointX, startPointY, "down", false);
			}
			if (maze[startPointX][startPointY + 1] == '.')
			{
				mazeTraverse(maze, startPointX, startPointY + 1, "right", false);
			}
		}
		if (direction == "down")
		{
			if (maze[startPointX][startPointY - 1] == '#' && maze[startPointX + 1][startPointY] == '.')
			{
				mazeTraverse(maze, startPointX + 1, startPointY, "down", false);
			}
			if (maze[startPointX][startPointY - 1] == '#' && maze[startPointX + 1][startPointY] == '#' && maze[startPointX][startPointY + 1] == '.')
			{
				mazeTraverse(maze, startPointX, startPointY, "right", false);
			}
			if (maze[startPointX][startPointY - 1] == '#' && maze[startPointX + 1][startPointY] == '#' && maze[startPointX][startPointY + 1] == '#')
			{
				mazeTraverse(maze, startPointX, startPointY, "up", false);
			}
			if (maze[startPointX][startPointY - 1] == '.')
			{
				mazeTraverse(maze, startPointX, startPointY - 1, "left", false);
			}
		}
	}
}

void print(char maze[12][12], int startPointX, int startPointY, string direction)
{
	Sleep(500);
	system("cls");
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i == startPointX && j == startPointY)
			{
				if (direction == "up")
				{
					cout << "^";
				}
				if (direction == "down")
				{
					cout << "V";
				}
				if (direction == "left")
				{
					cout << "<";
				}
				if (direction == "right")
				{
					cout << ">";
				}
				if (direction == "")
				{
					cout << "@";
				}
			}
			else
			{
				cout << maze[i][j];
			}
		}
		cout << endl;
	}
}

void mazeGenerator(char maze[12][12], int& startPointX, int& startPointY)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			maze[i][j] = '#';
		}
	}
	srand(time(0));
	startPointX = rand() % 12;
	startPointY = rand() % 12;
	maze[startPointX][startPointY] = '.';
	int x = startPointX, y = startPointY;
	while (!(x == 11 || y == 11 || x == 0 || y == 0))
	{
		int method = rand() % 4;
		switch (method)
		{
		case 0:
			if (y >= 1 && maze[x - 1][y - 1] == '#' && maze[x + 1][y - 1] == '#')
			{
				maze[x][--y] = '.';
			}
			break;
		case 1:
			if (y <= 10 && maze[x - 1][y + 1] == '#' && maze[x + 1][y + 1] == '#')
			{
				maze[x][++y] = '.';
			}
			break;
		case 2:
			if (x >= 1 && maze[x - 1][y - 1] == '#' && maze[x - 1][y + 1] == '#')
			{
				maze[--x][y] = '.';
			}
			break;
		case 3:
			if (x <= 10 && maze[x + 1][y - 1] == '#' && maze[x + 1][y + 1] == '#')
			{
				maze[++x][y] = '.';
			}
			break;
		default:
			break;
		}
	}
}
