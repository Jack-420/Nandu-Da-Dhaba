#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool Possible(long long a[],long long n, long long k, long long mid){
    sort(a,a+n);
    int count=1;
    int lastCow=a[0];
    for(int i=0;i<n;i++){
        if(a[i]-lastCow>=mid){
            count++;
            if(count==k){
                return true;
            }
            lastCow=a[i];
        }
    }
    return false;
}

long long AgressCow(long long a[],long long n, long long k){
    
    int s=0;
    long long maxi=-1;
    for(int i=0;i<n;i++) maxi=max(maxi,a[i]);
    int e=maxi;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(Possible(a,n,k,mid)){
            ans=mid;
            s=mid+1;
        } else {
            e=mid-1;
        }
    }
    return ans;
}

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
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<AgressCow(a,n,k);
    }
}