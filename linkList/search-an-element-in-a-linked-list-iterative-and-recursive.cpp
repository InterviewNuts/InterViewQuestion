#include<iostream>
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

void traverseList()
{
    Node* temp;

    // Return if list is empty 
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    temp = head;
    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data); // Print data of current node
        temp = temp->next;                 // Move to next node
    }
}

bool search(int data)
{
    Node* temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            break;
            return true;
        }
    }
    return false;
}

bool search_recursive(Node* head, int data)
{
    if (!head)
        return false;

    if (head->data == data)
        return true;

    return search_recursive(head->next, data);
}




int main()
{
    createList(4);
    traverseList();
    Node* t = head;
    cout << t->data << "\n";
    search_recursive(head, 33) ? cout << "Yes" : cout << "No";
    cout<<search_recursive(head, 33);
}