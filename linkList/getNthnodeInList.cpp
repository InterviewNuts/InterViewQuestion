#include<iostream>
#include<cassert>
using namespace std;

/* Link list node structure*/
class Node
{
public:
    int data;
    Node* next;
}*head;

void createList(int n)
{
    Node* newNode, * temp;
    int data, i;

    head = new Node();


    // Input data of node from the user
    cout << "Enter the data of node 1: ";
    cin >> data;

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL


    // Create n - 1 nodes and add to list
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newNode = new Node();


        cout << "Enter the data of node : ";
        cin >> data;

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL 

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
}


int GetNth(Node* head, int index)
{

    Node* current = head;

    // the index of the
    // node we're currently
    // looking at
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }

    /* if we get to this line,
    the caller was asking
    for a non-existent element
    so we assert fail */
    assert(0);
    return -1;
}
int main()
{
    createList(5);
    // Check the count
    // function
    cout << "Element at index 3 is " << GetNth(head, 3);
    return 0;
}
