#include <iostream>
#include <memory>

using namespace std;

void updateAccessibility(int accessibility[8][8], bool board[8][8]);
void initBoard(bool board[8][8]);
int findLittlestAccessibility(bool board[8][8], int accessibility[8][8], int row, int column);
int getAccessibility(bool board[8][8], int row, int column);

int horizontal[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int vertical[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main()
{
	bool board[8][8];
	initBoard(board);
	int accessibility[8][8];
	updateAccessibility(accessibility, board);
	for (int row = 0; row <= 7; row++)
	{
		for (int column = 0; column <= 7; column++)
		{
			int currentRow = row, currentColumn = column;
			cout << "Begins at (" << currentRow << ", " << currentColumn << ")" << endl;
			cout << "(" << currentRow << ", " << currentColumn << ") ";
			int littlestMoveNumber = findLittlestAccessibility(board, accessibility, currentRow, currentColumn);
			int counter = 0;
			do
			{
				currentRow += horizontal[littlestMoveNumber];
				currentColumn += vertical[littlestMoveNumber];
				board[currentRow][currentColumn] = true;
				counter++;
				cout << "-> (" << currentRow << ", " << currentColumn << ") ";
				updateAccessibility(accessibility, board);
				littlestMoveNumber = findLittlestAccessibility(board, accessibility, currentRow, currentColumn);
			} while (littlestMoveNumber != -1);
			cout << endl;
			cout << counter << " steps in all.\n" << endl;
			initBoard(board);
		}

	}
	return 0;
}

void updateAccessibility(int accessibility[8][8], bool board[8][8])
{
	for (int row = 0; row <= 7; row++)
	{
		for (int column = 0; column <= 7; column++)
		{
			int accessibilityForThisSquare = 0;
			for (int moveNumber = 0; moveNumber <= 7; moveNumber++)
			{
				if (row + horizontal[moveNumber] >= 0 && row + horizontal[moveNumber] <= 7 && column + vertical[moveNumber] >= 0 && column + vertical[moveNumber] <= 7)
				{
					if (!board[(row + horizontal[moveNumber])][(column + vertical[moveNumber])])
					{
						accessibilityForThisSquare++;
					}
				}
			}
			accessibility[row][column] = accessibilityForThisSquare;
		}
	}
}

void initBoard(bool board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = false;
		}
	}
}

int findLittlestAccessibility(bool board[8][8], int accessibility[8][8], int row, int column)
{
	int littlestMoveNumber = 0;
	int littlestAccessibility = 8;
	int littlestChildAccessibility = 8;
	bool isTheLastMovement = true;
	for (int moveNumber = 0; moveNumber <= 7; moveNumber++)
	{
		if (row + horizontal[moveNumber] >= 0 && row + horizontal[moveNumber] <= 7 && column + vertical[moveNumber] >= 0 && column + vertical[moveNumber] <= 7 && !board[(row + horizontal[moveNumber])][(column + vertical[moveNumber])])
		{
			if (accessibility[(row + horizontal[moveNumber])][(column + vertical[moveNumber])] < littlestAccessibility)
			{
				littlestMoveNumber = moveNumber;
				isTheLastMovement = false;
				littlestAccessibility = accessibility[(row + horizontal[moveNumber])][(column + vertical[moveNumber])];
			}
			if (accessibility[(row + horizontal[moveNumber])][(column + vertical[moveNumber])] == littlestAccessibility)
			{
				int newChildAccessibility = getAccessibility(board, row + horizontal[moveNumber], column + vertical[moveNumber]);
				int nowChildAccessibility = getAccessibility(board, row + horizontal[littlestMoveNumber], column + vertical[littlestMoveNumber]);
				if (newChildAccessibility < nowChildAccessibility)
				{
					littlestMoveNumber = moveNumber;
					littlestChildAccessibility = newChildAccessibility;
				}
			}
		}
	}
	if (isTheLastMovement)
	{
		return -1;
	}
	else
	{
		return littlestMoveNumber;
	}
}

int getAccessibility(bool board[8][8], int row, int column)
{
	int accessibilityForThisSquare = 0;
	for (int moveNumber = 0; moveNumber <= 7; moveNumber++)
	{
		if (row + horizontal[moveNumber] >= 0 && row + horizontal[moveNumber] <= 7 && column + vertical[moveNumber] >= 0 && column + vertical[moveNumber] <= 7)
		{
			if (!board[(row + horizontal[moveNumber])][(column + vertical[moveNumber])])
			{
				accessibilityForThisSquare++;
			}
		}
	}
	return accessibilityForThisSquare;
}