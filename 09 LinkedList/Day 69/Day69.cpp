#include<bits/stdc++.h>
using namespace std;
//Day 69 -Solution

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverse(Node*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* newHead = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        num1=reverse(num1);
        num2=reverse(num2);
        Node* result=nullptr;
        int carry=0;
        while(num1 || num2 || carry){
            int sum=carry;
            if(num1){
                sum+=num1->data;
                num1=num1->next;
            }
            if(num2){
                sum+=num2->data;
                num2=num2->next;
            }
            carry = sum/10;
            Node* newNode = new Node(sum%10);
            newNode->next=result;
            result=newNode;
        }
        // Removing any leading zeros
        while(result && result->data == 0 && result->next){
            Node* temp=result;
            result=result->next;
            delete temp;
        }
        return result;
    }