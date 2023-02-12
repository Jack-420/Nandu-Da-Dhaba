#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int val=this->data;
        if(next){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for data "<<val<<"\n";
    }
};

void print(Node *head)
{
    Node *temp1 = head;
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    cout << "\n";
}

int length(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node* &head, int position){
    if(position==1){
        Node* temp = head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt=1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next->prev=prev;
        curr->next=NULL;
        curr->prev=NULL;
        delete curr;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jack420
        // #define int long long

    Node *head = NULL;
    Node *tail = NULL;
    cout << length(head) << "\n";
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 200);
    insertAtHead(head, tail, 26);
    print(head);
    cout << length(head) << "\n";
    insertAtTail(head, tail, 90);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 80);
    insertAtTail(head, tail, 1000);
    print(head);
    cout << length(head) << "\n";
    insertAtPosition(head, tail, 1, 90);
    insertAtPosition(head, tail, 10, 990);
    print(head);
    cout << length(head) << "\n";   
    deleteNode(head,2);
    print(head);
    cout << length(head) << "\n";

}