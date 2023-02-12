#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    CircularQueue(int n){
        size=n;
        arr = new int[size];
        front=rear=-1;
    }
    bool enqueue(int value){
        if((front==0&&rear==size-1)||(rear==front-1)){
            cout<<"Queue is full\n";
            return false;
        } else if(front==-1) {
            front=rear=0;
        } else if(rear==size-1){
            rear=0;
        } else {
            rear++;
        }
        arr[rear]=value;
        return true;
    }
    int dequeue(){
        if(front==-1){
            cout<<"Queue is empty\n";
            return -1;
        }  
        int ans=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=rear=-1;
            return -1;
        } else if(front==size-1){
            front=0;
        } else {
            front++;
        }
        return ans;
    }
};


class Queue{
    public:
    int* a;
    int rear;
    int front;
    int size;
    
    Queue(int size){
        this->size=size;
        a=new int[size];
        rear=0; front=0;
    }

    void push_in(int x){
        if(rear==size)
        cout<<"Bhar gaya\n";
        else
        a[rear]=x;
        rear++;
    }

    int pop_out(){
        if(front==rear)
        return -1;
        else{
            int ans=a[front];
            a[front++]=-1;
            if(front==rear){
                front=0; rear=0;
            }
            return ans;
        }
    }

    int Upper(){
        if(front==rear)
        return -1;
        else
        return a[front];
    }

    bool Empty(){
        if(front==rear)
        return true;
        return false;
    }

    int Size(){
        return rear-front;
    }
};

void print(queue<int> p){
    while(!p.empty()){
        cout<<p.front()<<" ";
        p.pop();
    }
    cout<<"\n";
}

void reverseeee(queue<int> &p){
    if(p.size()==1)
    return;
    int x=p.front();
    p.pop();
    reverseeee(p);
    p.push(x);
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420

    queue<int> p;
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    print(p);
}