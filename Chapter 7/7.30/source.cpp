#include <iostream>
#include <cmath>

using namespace std;

const int END = -99999999;

int findIndex(int **bucket, int row);
void bucketSort(int numbersToSort[], int deepth, int length);
void modifyArray(int **bucket, int numbersToSort[], int length);

int main()
{
	int length;
	cout << "Please input the number of numbers to sort: ";
	cin >> length;
	int *numbersToSort = new int[length];
	if (numbersToSort != NULL)
	{
		for (int i = 0; i < length; i++)
		{
			cin >> numbersToSort[i];
		}
		bucketSort(numbersToSort, 1, length);
	}
	else
	{
		cout << "Too large to sort!" << endl;
	}
	for (int i = 0; i < length; i++)
	{
		cout << numbersToSort[i] << "\t";
	}
	cout << endl;
	return 0;
}

void bucketSort(int numbersToSort[], int deepth, int length)
{
	int **bucket = new int *[10];
	for (int i = 0; i <= 9; i++)
	{
		bucket[i] = new int[length];
		bucket[i][0] = END;
	}
	if (bucket != NULL)
	{
		bool isTheLastRow = true;
		for (int i = 0; i < length; i++)
		{
			int number = numbersToSort[i] / pow(10, deepth - 1);
			int digit = number % 10;
			if (number != 0)
			{
				isTheLastRow = false;

			}
			int index = findIndex(bucket, digit);
			bucket[digit][index] = numbersToSort[i];
			if (index < length - 1)
			{
				bucket[digit][index + 1] = END;
			}
		}
		modifyArray(bucket, numbersToSort, length);
		if (isTheLastRow)
		{
			return;
		}
		bucketSort(numbersToSort, deepth + 1, length);
		for (int i = 0; i <= 9; i++)
		{
			delete[] bucket[i];
		}
		delete[]bucket;
	}
	else
	{
		cout << "Too larget to create bucket!" << endl;
	}
}

int findIndex(int **bucket, int row)
{
	int i = 0;
	while (bucket[row][i] != END)
	{
		i++;
	}
	return i;
}

void modifyArray(int **bucket, int numbersToSort[], int length)
{
	int numbersArrayIndex = 0;
	for (int i = 0; i <= 9; i++)
	{
		int index = 0;
		while (bucket[i][index] != END && index < length)
		{
			numbersToSort[numbersArrayIndex++] = bucket[i][index++];
		}
	}
}