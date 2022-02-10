/**
 * @file LCA.cpp
 * @author Haramohan Sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-10
 *
 * @copyright Copyright (c) 2022
 *
 */
 /*
 Lowest Common Ancestor of Two Nodes in a Tree
  Theoretical Idea
 The idea of this approach is to have two pointers, one on each node. We need to move these pointers towards the root
 in a way that allows them to meet at the LCA.

 The first thing we can notice is that these pointers should be in the same depth. In addition to that,
 the deeper pointer can never be the LCA. Therefore, our first step should be to keep moving the deeper pointer
 to its parent until the two pointers are on the same depth.

 Now, we have two pointers that are on the same depth. We can keep moving both pointers
 towards the root one step at a time until they meet at one node. Since this node is the deepest node
 that our pointers can meet at, therefore, it’s the deepest common ancestor of our starting node, 
 which is the LCA.

Link:

https://www.baeldung.com/cs/tree-lowest-common-ancestor#:~:text=2.-,Definition,the%20root%20to%20(including%20).


 */
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left, * right = nullptr;
    Node(int data) :data(data), left(nullptr), right(nullptr) {};
};


Node* BST_Insert(Node* head, int data)
{
    if (!head)
        return new Node(data);
    if (head->data < data)
        head->left = BST_Insert(head->left, data);
    else  if (head->data > data)
        head->right = BST_Insert(head->right, data);

    return head;
}

void InOrder(Node* p)
{
    if (p)
    {
        InOrder(p->left);
        cout << p->data << " ";
        InOrder(p->right);

    }

}
Node* LCA(Node* p, int a, int b)
{
    if (p == nullptr)
    {
        return nullptr;
    }
    if (p->data == a || p->data == b)
    {
        return p;
    }

    Node* left = LCA(p->left, a, b);
    Node* right = LCA(p->right, a, b);

    if (left && right)
    {
        return p;
    }
    else
    {
        return (left) ? left : right;
        // if (left)
        //     return left;
        // else if (right)
        //     return right;
    }
}

int main()
{
    Node* tree = BST_Insert(tree, 50);
    tree = BST_Insert(tree, 30);
    tree = BST_Insert(tree, 25);
    tree = BST_Insert(tree, 35);
    tree = BST_Insert(tree, 33);
    tree = BST_Insert(tree, 36);
    tree = BST_Insert(tree, 37);
    tree = BST_Insert(tree, 39);
    tree = BST_Insert(tree, 60);
    tree = BST_Insert(tree, 55);
    tree = BST_Insert(tree, 65);
    tree = BST_Insert(tree, 62);

    InOrder(tree);
    cout << "\n";
    Node* lca_node = LCA(tree, 39, 62);
    cout << " LCA VALUE = " << lca_node->data << "\n";




}