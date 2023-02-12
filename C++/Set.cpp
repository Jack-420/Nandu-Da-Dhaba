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

    set<int> s;

    s.insert(5);
    s.insert(6);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(9);

    for(auto i:s)
    cout<<i<<" ";
    cout<<"\n";
    s.erase(s.begin()+1);

    for(auto i:s)
    cout<<i<<" ";

}