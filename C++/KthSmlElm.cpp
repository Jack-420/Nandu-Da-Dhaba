#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int Possible(int a[], int n, int mid, int k){
    int count =0;
    for(int i=0;i<n;i++){
        if(a[i]<=mid)
        count++;
    }
    if(count>=k)
    return 1;
    else
    return 0;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    // #define int long long

    int t;
    cin>>t;
    while(t--) 
    {
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int s=INT_MAX,e=INT_MIN;
        for(int i=0;i<n;i++){
            if(a[i]<s)
            s=a[i];
            if(a[i]>e)
            e=a[i];
        }
        while(s<=e){
            int mid=s+(e-s)/2;
            if(Possible(a,n,mid,k)){
                if(Possible(a,n,mid-1,k)){
                    e=mid-1;
                } else {
                    cout<<mid;
                    break;
                }
            } else {
                s=mid+1;
            }
        }
    }
}