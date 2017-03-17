#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void mazeTraverse(char maze[12][12], int startPointX, int startPointY, string direction, bool isTheFirstStep);
void print(char maze[12][12], int startPointX, int startPointY, string direction);


int main()
{
	char maze[12][12] = { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'}, {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'}, {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'}, {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'}, {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'}, {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'}, {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'}, {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'}, {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'}, {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'}, {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };
	mazeTraverse(maze, 2, 0, "", true);
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
	Sleep(200);
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

