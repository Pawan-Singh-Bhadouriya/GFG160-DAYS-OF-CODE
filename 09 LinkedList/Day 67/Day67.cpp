using namespace std;
#include <bits/stdc++.h>
// Day 67 - Solution

struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* dummy = new Node(-1);
        Node* tail=dummy;
        
        Node* temp1=head1;
        Node* temp2=head2;
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data < temp2->data){
                tail->next=temp1;
                temp1= temp1->next;
            }
            else{
                tail->next=temp2;
                temp2= temp2->next;
            }
            tail=tail->next;
        }
        
        if(temp1!=NULL){
            tail->next=temp1;
        }
        else if(temp2!=NULL){
            tail->next=temp2;
        }
        
        return dummy->next;
    }