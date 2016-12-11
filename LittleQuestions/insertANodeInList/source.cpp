#include <iostream>

using namespace std;

struct Node
{
    Node* head;
    int data;
    Node* after;
};

int main()
{
    Node* linkedList = new Node;
    Node* head = linkedList;
    for (int i = 1; i <= 10; i++)
    {
        linkedList->data = i;
        linkedList->head = head;
        linkedList->after = new Node;
        linkedList = linkedList->after;
    }
    linkedList = head;
    while (linkedList->after != NULL)
    {
        cout << linkedList->data << "\t";
        linkedList = linkedList->after;
    }
    cout << "\nNow insert a Node before the first Node" << endl;
    Node* newNode = new Node;
    linkedList = head;
    linkedList->
    return 0;
}