#include <iostream>

using namespace std;

void output(bool board[8][8]);
void findQueens(bool board[8][8], int row);
bool isSuitableHere(bool board[8][8], int row, int column);
void initBoard(bool board[8][8]);

int counter = 0;

int main()
{
	bool board[8][8];
	initBoard(board);
	findQueens(board, 0);
	cout << counter << " in total." << endl;
	return 0;
}

void findQueens(bool board[8][8], int row)
{
	if (row == 8)
	{
		output(board);
	}
	else
	{
		for (int i = 0; i <= 7; i++)
		{
			board[row][i] = true;
			if (isSuitableHere(board, row, i))
			{
				findQueens(board, row + 1);
			}
			board[row][i] = false;
		}
	}
}

bool isSuitableHere(bool board[8][8], int row, int column)
{
	int counter = 0;
	for (int i = 0; i <= 7; i++)
	{
		if (board[row][i])
		{
			counter++;
		}
	}
	if (counter != 1)
	{
		return false;
	}
	counter = 0;
	for (int i = 0; i <= 7; i++)
	{
		if (board[i][column])
		{
			counter++;
		}
	}
	if (counter != 1)
	{
		return false;
	}
	counter = 0;
	int diagonalRow = row;
	int diagonalColumn = column;
	while (diagonalRow >= 0 && diagonalColumn >= 0)
	{
		if (board[diagonalRow--][diagonalColumn--])
		{
			counter++;
		}
	}
	diagonalRow = row;
	diagonalColumn = column;
	while (diagonalRow >= 0 && diagonalColumn <= 7)
	{
		if (board[diagonalRow--][diagonalColumn++])
		{
			counter++;
		}
	}
	diagonalRow = row;
	diagonalColumn = column;
	while (diagonalRow <= 7 && diagonalColumn <= 7)
	{
		if (board[diagonalRow++][diagonalColumn++])
		{
			counter++;
		}
	}
	diagonalRow = row;
	diagonalColumn = column;
	while (diagonalRow <= 7 && diagonalColumn >= 0)
	{
		if (board[diagonalRow++][diagonalColumn--])
		{
			counter++;
		}
	}
	if (counter != 4)
	{
		return false;
	}
	return true;
}

void initBoard(bool board[8][8])
{
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			board[i][j] = false;
		}
	}
}

void output(bool board[8][8])
{
	cout << "-------------------------------------------------------------" << endl;
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (board[i][j])
			{
				cout << "*\t";
			}
			else
			{
				cout << "O\t";
			}
		}
		cout << endl;
	}
	cout << endl;
	counter++;
}