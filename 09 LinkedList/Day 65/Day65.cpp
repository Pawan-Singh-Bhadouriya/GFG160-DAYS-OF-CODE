using namespace std;
#include <bits/stdc++.h>
// Day 65 - Solution

struct Node
{
    int data;
    struct Node *next;
}

Node *reverseList(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}