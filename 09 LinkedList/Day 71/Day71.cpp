#include<bits/stdc++.h>
using namespace std;
//Day 71 -Solution

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

bool detectLoop(Node *head)
{
    Node *slow = head; // we can aslo call it turtle
    Node *fast = head; // we can also call it Hare

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}