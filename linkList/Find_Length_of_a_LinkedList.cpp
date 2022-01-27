/**
 * @file Find_Length_of_a_LinkedList.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-27
 *
 * @copyright Copyright (c) 2022
 *
 */


 /*
 Iterative Solution

 1) Initialize count as 0
 2) Initialize a node pointer, current = head.
 3) Do following while current is not NULL
      a) current = current -> next
      b) count++;
 4) Return count
 */



#include<iostream>
using namespace std;

/* Link list node structure*/
class Node
{
public:
    int data;
    Node* next;
};



Node* insertinList(Node* start, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = start;

    /* move the head to point to the new node */
    start = new_node;
    return start;
}


/* Counts no. of nodes in linked list */
int getCount(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}


/* Recursively count number of nodes in linked list */
 /*
 Recursive Solution

 int getCount(head)
 1) If head is NULL, return 0.
 2) Else return 1 + getCount_recursive(head->next)
 */
int getCount_recursive(Node* head)
{
    int count = 1;
    if (!head)
        return 0;
    else
    {
        count = count + getCount_recursive(head->next);
    }
    return count;
}


/* Driver program to test count function*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    /* Use push() to construct below list
    1->2->1->3->1 */
    head = insertinList(head, 1);
    head = insertinList(head, 3);
    head = insertinList(head, 1);
    head = insertinList(head, 2);
    head = insertinList(head, 1);

    /* Check the count function */
    cout << "count of nodes is " << getCount(head) << "\n";

    /* Check the count function */
    cout << "Recursive count of nodes is " << getCount_recursive(head) << "\n";
    return 0;
}