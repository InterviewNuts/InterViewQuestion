#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d) :data(d), next(nullptr) {}
};

Node* getNode(int data)
{
    return new Node(data);
}
Node* insert(Node* head, int data)
{
    Node* temp = getNode(data);
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        Node* temp1 = head;
        while (temp1->next != nullptr)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
return head;
}

void printList(Node* head)
{
    if (head == nullptr) {
        cout << "\n";
        return;
    }
    cout << head->data << " ";
    printList(head->next);

}


int main()
{
    Node* head = nullptr;
    head = insert(head, 10);
    head = insert(head, 30);
    head = insert(head, 110);
    head = insert(head, 102);
    head = insert(head, 1011);
    printList(head);
}