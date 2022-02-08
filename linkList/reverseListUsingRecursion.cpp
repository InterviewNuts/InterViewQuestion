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

void printListForward(Node* head)
{
    if (head == nullptr) {
        cout << "\n";
        return;
    }
    cout << head->data << " ";
    printListForward(head->next);


}

void printListReverse(Node* head)
{

    if (head == nullptr) {
        cout << "\n";
        return;
    }

    printListForward(head->next);
    cout << head->data << " ";


}

Node* start;
void reverseList(Node* p)
{
    if (p->next == nullptr)
    {
        start = p;
        return;
    }
    reverseList(p->next);
    Node* t = p->next;
    t->next = p;
    p->next = nullptr;
}

int main()
{
    Node* head = nullptr;
    head = insert(head, 10);
    head = insert(head, 30);
    head = insert(head, 110);
    head = insert(head, 102);
    head = insert(head, 1011);
 start=head;
    printListForward(head);
    cout << " after reversal \n";
    head = start;
    reverseList(head);
    head = start;
    printListForward(head);


}