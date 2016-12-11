#include <iostream>

using namespace std;

void quickSort(int data[], int startIndex, int endIndex);
void print(int data[], int length);

int main()
{
	int length;
	cout << "How many numbers do you have: ";
	cin >> length;
	cout << "Please input your numbers: ";
	int *data = new int[length];
	if (data != NULL)
	{
		for (int i = 0; i < length; i++)
		{
			cin >> data[i];
		}
		quickSort(data, 0, length - 1);
		print(data, length);
	}
	else
	{
		cout << "Out of memory limit." << endl;
	}
	return 0;
}

void quickSort(int data[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int swap = data[startIndex], s = startIndex, e = endIndex;
		while (s < e)
		{
			while (s < e && data[e] >= swap)
			{
				e--;
			}
			if (s < e)
			{
				data[s] = data[e];
			}
			while (s < e && data[s] <= swap)
			{
				s++;
			}
			if (s < e)
			{
				data[e] = data[s];
			}
		}
		data[s] = swap;
		quickSort(data, startIndex, s - 1);
		quickSort(data, s + 1, endIndex);
	}
}

void print(int data[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}