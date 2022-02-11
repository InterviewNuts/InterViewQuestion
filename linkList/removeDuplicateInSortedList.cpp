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

void removeDuplicateFromSortedList(Node* head)
{
    Node* p = head;
    Node* q;
    while (p != nullptr && p->next != nullptr)
    {
        if (p->data == p->next->data)
        {
            q = p->next->next;
            if (q == nullptr) {
                p->next = nullptr;
                break;
            }
            p->next = q;
        }
        if (p->data != p->next->data)
            p = p->next;
    }

}

int main()
{
    Node* start;
    Node* head = nullptr;
    head = insert(head, 10);
    head = insert(head, 30);
    head = insert(head, 30);
    head = insert(head, 30);
    head = insert(head, 30);
    head = insert(head, 1011);
    start = head;
    printListForward(head);
    head = start;
    removeDuplicateFromSortedList(head);
    head = start;
    printListForward(head);
    return 0;
}