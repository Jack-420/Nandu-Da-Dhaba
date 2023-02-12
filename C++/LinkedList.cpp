#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->data){
            delete next;
            this->next=NULL;
        }
        cout<<"Node is free with data "<<value<<"\n";
    }
};

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
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

void deleteNode(Node* &head, int position){
    if(position==1){
        Node* temp = head;
        head = head -> next;
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
        curr->next=NULL;
        delete curr;
    }
}

Node* getMiddle(Node* &head){
    if(head==NULL)
    return head;
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* kReverse(Node* head, int k){
    if(head==NULL)
    return head;
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    int cnt=0;
    while(curr!=NULL&&cnt<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    head->next=curr;
    return prev;
}

Node* reverseEvenLengthGroups(Node* head){
    int sum=0,count=0,group=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        count++;
        if(count>sum){
            group+=1;
            if(group%2==0){
                count+=group-1;
                prev->next=kReverse(temp,group);
            }
            sum+=group;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

bool isCircular(Node* &head){
    if(head==NULL)
    return true;
    Node* temp=head->next;
    while(1){
        if(temp==NULL)
        return false;
        else if(temp==head)
        return true;
        temp=temp->next;
    }
}

bool detectLoop(Node* &head){
    if(head==NULL)
    return false;
    Node* temp=head;
    map<Node*,bool> visited;
    while(temp!=NULL){
        if(visited[temp]==true)
        return true;
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

Node* floydDetectLoop(Node* &head){
    if(head==NULL)
    return NULL;
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL&&fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
        fast=fast->next;
        slow=slow->next;
        if(fast==slow)
        return slow;
    }
    return NULL;
}

Node* startLoop(Node* &head){
    if(head==NULL)
    return NULL;
    Node* intersection=floydDetectLoop(head);
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    if(head==NULL)
    return ;
    Node* temp1=startLoop(head);
    Node* temp2=temp1;
    while(1){
        if(temp2->next==temp1){
            temp2->next=NULL;
            return ;
        }
        temp2=temp2->next;
    }
}

void removeDublicateSorted(Node* head){
    if(head==NULL)
    return ;
    Node* curr=head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node* fnext=curr->next;
            Node* next_next=curr->next->next;
            curr->next=next_next;
            fnext->next=NULL;
            delete fnext;
        } else {
            curr=curr->next;
        }
    }
    return ;
}

Node* mergeTwoSortedLL(Node* left, Node* right){
    if(left==NULL)
    return right;
    if(right==NULL)
    return left;
    Node* ans = new Node(-1);
    Node* temp=ans;
    while(left!=NULL&&right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            left=left->next;
            temp=temp->next;
        } else {
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
    }
    while(left!=NULL){
        temp->next=left;
        left=left->next;
        temp=temp->next;
    }
    while(right!=NULL){
        temp->next=right;
        right=right->next;
        temp=temp->next;
    }
    return ans->next;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void sortedInsert(Node* &head, int data){
    if(head==NULL)
    InsertAtHead(head,data);
    Node* temp1 = NULL;
    Node* temp2 = head;
    while(temp2->data<=data){
        temp1=temp2;
        temp2=temp2->next;
    }
    Node* temp3 = new Node(data);
    temp1->next=temp3;
    temp3->next=temp2;
}


int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    Node* node1 = new Node(NULL);
    Node* head = node1;
    Node* tail = node1;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            int d; cin>>d;
            if(i==0)
        }
    }
}