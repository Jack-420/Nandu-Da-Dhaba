#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    // max heap
    priority_queue<int> maxi;

    // min heap
    priority_queue<int,vector<int>,greater<int>> mini;

    maxi.push(1);
    maxi.push(5);
    maxi.push(9);
    maxi.push(4);

    mini.push(8);
    mini.push(6);
    mini.push(0);
    mini.push(2);

    for(int i=0;i<4;i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<"\n";
    for(int i=0;i<4;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
}