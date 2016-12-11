#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

void moveTortoise(int* tortoise);
void moveHare(int* hare);
void print(int* tortoise, int* hare);
bool competition();

int main()
{
	while (competition());
	system("pause");
	return 0;
}

bool competition()
{
	int tortoise = 1;
	int hare = 1;
	int steps = 0, tortoiseStep = 0, hareStep = 0;
	cout << "BANG!!!!!\nAND THEY'RE OFF!!!!!" << endl;
	while (!(hare == 70 && tortoise == 70))
	{
        Sleep(1000);
		moveTortoise(&tortoise);
		moveHare(&hare);
		steps++;
		print(&tortoise, &hare);
		if (tortoise == 70 && tortoiseStep == 0)
		{
			tortoiseStep = steps;
		}
		if (hare == 70 && hareStep == 0)
		{
			hareStep = steps;
		}
	}
	if (hareStep < tortoiseStep)
	{
		cout << "Hare wins, Yuch." << endl;
	}
	else if (tortoiseStep < hareStep)
	{
		cout << "TORTOISE WINS!!! YAY!!!" << endl;
	}
	else
	{
		cout << "It's a tie." << endl;
		return true;
	}
	return false;
}

void moveTortoise(int* tortoise)
{
	if (*tortoise == 70)
	{
		return;
	}
	srand(clock());
	int percentage = rand() % 10 + 1;
	if (percentage >= 1 && percentage <= 5)
	{
		*tortoise += 3;
		if (*tortoise > 70)
		{
			*tortoise = 70;
		}
	}
	if (percentage >= 6 && percentage <= 7)
	{
		*tortoise = *tortoise - 6;
		if (*tortoise <= 0)
		{
			*tortoise = 1;
		}
	}
	if (percentage >= 8 && percentage <= 10)
	{
		*tortoise += 1;
	}
}

void moveHare(int* hare)
{
	if (*hare == 70)
	{
		return;
	}
	srand(clock());
	int percentage = rand() % 10 + 1;
	if (percentage >= 3 && percentage <= 4)
	{
		*hare += 9;
		if (*hare > 70)
		{
			*hare = 70;
		}
	}
	if (percentage == 5)
	{
		*hare = *hare -12;
		if (*hare <= 0)
		{
			*hare = 1;
		}
	}
	if (percentage >= 6 && percentage <= 8)
	{
		*hare += 1;
	}
	if (percentage >= 9 && percentage <= 10)
	{
		*hare -= 2;
		if (*hare <= 0)
		{
			*hare = 1;
		}
	}
}

void print(int* tortoise, int* hare)
{
	for (int j = 1; j <= 7; j++)
	{
		for (int i = 1; i <= 10; i++)
			cout << i % 10;
	}
	cout << endl;
	for (int i = 1; i <= 70; i++)
	{
		if (*tortoise == i && *tortoise == *hare)
		{
			cout << "OUCH!!";
		}
		else if (*tortoise == i)
		{
			cout << "T";
		}
		else if (*hare == i)
		{
			cout << "H";
		}
		else
		{
			cout << " ";
		}
	}
	cout << "\n\n" << endl;
}