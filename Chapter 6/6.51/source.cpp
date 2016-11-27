#include <iostream>

using namespace std;

int tripleByValue(int count);
void tripleByReference(int& count);

int main()
{
    int count;
    cout << "Please input a count: ";
    cin >> count;
    count = tripleByValue(count);
    cout << "The result of function tripleByValue is " << count << "." << endl;
    tripleByReference(count);
    cout << "The result of function tripleByReference is " << count << "." << endl;
}

int tripleByValue(int count)
{
    return count * 3;
}

void tripleByReference(int& count)
{
    count = count * 3;
    return;
}