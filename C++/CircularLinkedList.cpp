#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node{
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

void insertNode(Node* &tail, int element, int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        temp->next=temp;
    } else {
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void print(Node* &tail){
    Node* temp = tail;
    if(tail==NULL){
        cout<<"List is empty \n";
        return;
    }
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
    cout<<endl;
}

void deleteNode(Node* &tail, int element){
    if(tail==NULL){
        cout<<"The list is empty \n";
        return;
    }
    Node* curr=tail->next;
    Node* prev=tail;
    while(curr->data!=element){
        prev=curr;
        curr=curr->next;
    }
    if(curr==tail)
    tail=tail->next;
    if(curr==prev)
    tail=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    Node* tail=NULL;
    insertNode(tail,2,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    insertNode(tail,5,6);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,5);
    print(tail);
    deleteNode(tail,4);
    print(tail);
    deleteNode(tail,6);
    print(tail);
}