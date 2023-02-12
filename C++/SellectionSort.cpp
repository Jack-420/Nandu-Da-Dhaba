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
        for(int i=0;i<n-1;i++){
            int min = i;
            for(int j=i+1;j<n;j++){
                if(a[min]>a[j])
                    min = j;
            }
            swap(a[min],a[i]);
        }
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
    }
}