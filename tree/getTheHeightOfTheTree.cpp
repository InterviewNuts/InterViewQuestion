/**
 * @file getTheHeightOfTheTree.cpp
 * @author Haramohan sahu (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include<iostream>
#include<exception>
using namespace std;

class Node
{
public:
    Node* lChild;
    int data;
    Node* rChild;
};

class Tree
{
private:
    Node* root = nullptr;
public:
    Node* getRoot() { return root; }
    Tree() :root(nullptr) {};
    Node* createTree(Node* r, int data);
    void preOrder(Node* r);
    void postOrder(Node* r);
    void inOrder(Node* r);
    int heightOfTheTree(Node* p);
};

int Tree::heightOfTheTree(Node* p)
{
    if (p == nullptr)
        return 0;

    int left = heightOfTheTree(p->lChild);
    int right = heightOfTheTree(p->rChild);
    int h;
	// return max( left,right)+1;
    if (left > right)
    {
        h = 1 + left;
    }
    else {
        h = 1 + right;
    }
    return h;
}

Node* Tree::createTree(Node* r, int data)
{
    Node* p = nullptr;
    if (!r) {
        //! this code is for first time, this ccan be improved. 
        r = new Node();
        r->data = data;
        r->lChild = r->rChild = nullptr;
        if (!root)
        {
            root = r;
        }
        return r;
    }
    if (data < r->data)
        r->lChild = createTree(r->lChild, data);
    else if (data > r->data)
        r->rChild = createTree(r->rChild, data);
    return r;
}
void Tree::preOrder(Node* p)
{
    if (p)
    {
        cout << p->data << endl;
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}
void Tree::inOrder(Node* p)
{
    if (p)
    {
        inOrder(p->lChild);
        cout << p->data << endl;
        inOrder(p->rChild);
    }
}
void Tree::postOrder(Node* p)
{
    if (p)
    {
        postOrder(p->lChild);
        postOrder(p->rChild);
        cout << p->data << endl;
    }
}



int main()
{

    Tree* rootTree = new Tree();

    Node* r = rootTree->createTree(rootTree->getRoot(), 50);
    r = rootTree->createTree(r, 4);
    r = rootTree->createTree(r, 3);
    r = rootTree->createTree(r, 2);
    r = rootTree->createTree(r, 1);
    // r = rootTree->createTree(r, 60);
    // r = rootTree->createTree(r, 40);
    // r = rootTree->createTree(r, 20);
    // r = rootTree->createTree(r, 80);
    // r = rootTree->createTree(r, 45);
    // r = rootTree->createTree(r, 55);


    rootTree->inOrder(rootTree->getRoot());

    cout << "Height of the tree =" << rootTree->heightOfTheTree(r);


    return 0;
}
