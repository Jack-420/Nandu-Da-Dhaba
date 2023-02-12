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

    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mid==0||mid==n-1||a[mid]>=a[mid-1]&&a[mid]>=a[mid+1]){
                cout<<a[mid];
                break;
            } else if(a[mid]>=a[mid-1]){
                s=mid+1;
            } else {
                e=mid-1;
            }
        }
    }
}