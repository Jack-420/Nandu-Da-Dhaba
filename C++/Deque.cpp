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

    deque<int> d;

    d.push_back(1);
    d.push_front(2);

    for(int i:d)
    cout<<i<<" ";
    cout<<"\n";

    // d.pop_back();

    // for(int i:d)
    // cout<<i<<" ";
    // cout<<"\n";

    cout<<"Is the DQ empty ?"<<"\n"<<d.empty();

    cout<<"\n";

    cout<<"Size is "<<d.size()<<"\n";

    d.erase(d.begin()); // Or d.erase(d.begin(),d.begin()+1);

    cout<<"Size is "<<d.size()<<"\n";

}