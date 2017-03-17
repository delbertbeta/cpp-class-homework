#include <iostream>

using namespace std;

struct Node
{
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
        linkedList->after = new Node;
        linkedList = linkedList->after;
    }
    linkedList = head;
    while (linkedList->after != NULL)
    {
        cout << linkedList->data << "\t";
        linkedList = linkedList->after;
    }
    cout << endl;
    linkedList = head;
    cout << "Choose a node to insert another node before it: ";
    int nodeIndex;
    cin >> nodeIndex;
    for (int i = 1; i < nodeIndex; i++)
    {
        linkedList = linkedList->after;
    }
    Node* nextNode = linkedList->after;
    Node* newNode = new Node;
    cout << "Input the data for new node: ";
    cin >> newNode->data;
    newNode->after = nextNode;
    linkedList->after = newNode;
    linkedList = head;
    while (linkedList->after != NULL)
    {
        cout << linkedList->data << "\t";
        linkedList = linkedList->after;
    }
    return 0;
}