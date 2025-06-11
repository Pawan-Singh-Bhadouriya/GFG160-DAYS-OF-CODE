#include <bits/stdc++.h>
using namespace std;
// Day 73 -Solution

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


void removeLoop(Node* head) {
        if(head==NULL || head->next==NULL) return;
        
        Node* slow=head;
        Node* fast=head;
        
        slow=slow->next;
        fast=fast->next->next;
        
        while(fast && fast->next){
    
            if(slow==fast) break;
            
            slow=slow->next;
            fast=fast->next->next;
        }
                
        if(slow == fast){
            slow=head;
            
            if(slow == fast){
                while(fast->next != slow){
                    fast=fast->next;
                }
            }
            else{
                while(slow->next!=fast->next){
                    slow=slow->next;
                    fast=fast->next;
                }
            }
            fast->next=nullptr;
        }
        
    }