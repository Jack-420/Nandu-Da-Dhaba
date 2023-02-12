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

    list<int> l;

    l.push_back(1);
    l.push_front(2);

    for(int i:l)
    cout<<i<<" ";

    cout<<"\n";

    cout<<"Size before erasing is "<<l.size()<<"\n";

    l.erase(l.begin()); // Or d.erase(d.begin(),d.begin()+1);

    cout<<"Size after erasing is "<<l.size()<<"\n";

}