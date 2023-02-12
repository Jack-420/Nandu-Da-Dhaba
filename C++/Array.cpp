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

    array<int,5> a;
    a.fill(10);
    a.at(2);
    for(int i=0;i<5;i++){
        cout<<a.at(i)<<" ";
    }
    cout<<"\n";
    // Iterators 
    // begin(),end(),rbegin(),rend().
    array<int,5> arr = {1,2,3,4,5};
    for(auto it=arr.begin();it!=arr.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    for(auto it=arr.rbegin();it!=arr.rend();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";

    string s = "mrinal";
    for(auto c:s){
        cout<<c<<" ";
    }
    cout<<"\n";

    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<"\n";
    cout<<arr.size()<<"\n";
    cout<<arr.front()<<"\n";
    cout<<arr.back()<<"\n";
    cout<<*arr.begin()<<"\n";
    cout<<*arr.rbegin()<<"\n";
    cout<<*arr.end()<<"\n";
    cout<<*arr.rend()<<"\n";
}