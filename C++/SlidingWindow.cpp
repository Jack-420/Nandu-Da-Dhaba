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

    int n,d,max=0; cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<d;i++){
        max+=a[i];
    }
    for(int i=0;i<n-d;i++)
        if(max-a[i]+a[i+d]>=max)
            max=max-a[i]+a[i+d];
    cout<<max;
}