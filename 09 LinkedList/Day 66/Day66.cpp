using namespace std;
#include <bits/stdc++.h>
// Day 66 - Solution



struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }

};

int
len(Node *head)
{
    Node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

Node *rotate(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }

    int size = len(head);
    k = k % size;
    if (k == 0)
        return head;

    Node *newTail = head;

    for (int i = 1; i < k; i++)
    {
        newTail = newTail->next;
    }

    Node *newHead = newTail->next;
    newTail->next = NULL;

    Node *tail = newHead;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = head;

    return newHead;
}