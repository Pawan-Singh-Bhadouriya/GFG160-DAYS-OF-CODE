#include<bits/stdc++.h>
using namespace std;
//Day 68 -Solution

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }

} *head;

Node *reverseKGroup(Node *head, int k)
{
    if (head == NULL || k == 1)
        return head;

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    int count = 0;
    Node *temp = head;
    while (temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }
    if (count < k)
    {
        count = 0;
        temp = head;
        while (temp != NULL && count < k)
        {
            temp = temp->next;
            count++;
        }
    }
    count = 0;
    curr = head;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverseKGroup(next, k);
    }
    return prev;
}