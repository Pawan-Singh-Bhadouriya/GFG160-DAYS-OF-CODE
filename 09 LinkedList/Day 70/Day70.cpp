#include<bits/stdc++.h>
using namespace std;
//Day 70 -Solution

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node *cloneLinkedList(Node *head) {
        // Write your code here
        if(head==NULL) return nullptr;
        
        Node* curr=head;
        while(curr){
            Node* copy=new Node(curr->data);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
        
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr=curr->next->next;
        }
        
        Node* dummy = new Node(0);
        Node* copycurr = dummy;
        curr=head;
        
        while(curr){
            copycurr->next=curr->next;
            curr->next=curr->next->next;
            curr=curr->next;
            copycurr=copycurr->next;
        }
        return dummy->next;
    }