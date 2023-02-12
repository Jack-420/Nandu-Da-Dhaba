#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define int long long

class Node{
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
    }
};

void push_in(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void pop_out(Node* head){
    if(head==NULL){
        cout<<"Empty";
        return;
    }
    head=head->next;
}

bool isEmpty(Node* head){
    return head;
}

int mod(int n){
    return n % 1000000007;
}

bool isprime(int n){
    if(n==1) ret false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) ret false;
    ret true;
}

int isSquare(int n){
    int l=1,h=n;
    while(l<=h){
        int mid=(l+h)/2;
        if(mid*mid==n) return mid;
        if(mid*mid<n) l=mid+1;
        else h=mid-1;
    }
    return -1;
}

bool cmp(int a, int b){
    return a>b;
}

int power(int a,int b){
    int temp=1;
    while(b--)
        temp*=a;
    return temp;
}

void code(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420

    int t;
    cin>>t;
    while(t--)
    {
        code();
        cout<<endl;
    }
}