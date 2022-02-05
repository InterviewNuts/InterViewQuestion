#include <iostream>
using namespace std;


class  Node
{
public:
    Node() = default;
    Node(int d) :data(d), npx(nullptr)
    {

    }

    int data;
    class Node* npx; /* XOR of next and previous node */
}*start = nullptr, * c = nullptr, * p = nullptr;


/* returns XORed value of the node addresses */
Node* XOR(Node* a, Node* b)
{
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(a) ^
        reinterpret_cast<uintptr_t>(b));
}


void create()
{
    int data;
    start = c = p = nullptr;

    while (true)
    {
        cout << " Please the data to List or -1 to break ";
        cin >> data;
        if (data == -1)
            break;
        c = new Node(data);
        c->npx = XOR(p, nullptr);
        if (start == nullptr)
        {
            start = p = c;
        }
        else
        {
            p->npx = XOR(c, XOR(p->npx, nullptr));
        }
        p = c;
    }
}

// Helper function to traverse the list in a forward direction
void traverse(Node* head)
{
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;

    while (curr != nullptr)
    {
        cout << curr->data << "--> ";

        // `next` node would be xor of the address of the previous node
        // and current node link
        next = XOR(prev, curr->npx);

        // update `prev` and `curr` pointers for the next iteration of the loop
        prev = curr;
        curr = next;
    }

    cout << "nullptr";
}

int main()
{

    Node* head = nullptr;
    create();


    traverse(start);

    return 0;
}

