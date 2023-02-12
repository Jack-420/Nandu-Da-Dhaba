#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define adiwish ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        adiwish
    #define int long long

    int t;
    cin>>t;
    while(t--) 
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=1;i<n;i++) {
            for(int j=0;j<n-i;j++) {
                if(a[j]>a[j+1]) {
                    swap(a[j],a[j+1]);
                }
            }
        }
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
    }
}