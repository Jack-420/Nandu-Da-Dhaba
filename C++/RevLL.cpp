#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node {
    public:
    int data;
    Node* next;

    // Constructor.
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    // Destructor.
    ~Node(){
        int value = this->data;
        // memory free.
        if(this->data){
            delete next;
            this->next=NULL;
        }
        cout<<"Node is free with data "<<value<<"\n";
    }
};

void InsertAtHead(Node* &head, int d){
    // Create new node.
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    // Create new node.
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &tail,Node* &head, int position, int d) {
    if(position==1){
        InsertAtHead(head,d);
        return ;
    }

    Node* temp = head;
    int cnt=1;
    
    while(cnt<position-1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next==NULL){
        InsertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

Node* reverse1(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* chotaHead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotaHead;
}

Node* reverse2(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

void reverse3(Node* &head, Node* curr, Node* prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    Node* forward=curr->next;
    reverse3(head,forward,curr);
    curr->next=prev;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    InsertAtHead(head,12);
    InsertAtTail(tail,15);
    InsertAtTail(tail,6);
    InsertAtPosition(tail,head,3,22);

    print(head);

    head=reverse1(head);
    print(head);
    head=reverse2(head);
    print(head);
    Node* curr=head;
    Node* prev=NULL;
    reverse3(head,curr,prev);
    print(head);
}