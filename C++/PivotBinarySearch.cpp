#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

long long pivot(long long a[], long long s, long long e){
    while(s<e){
        int mid=s+(e-s)/2;
        if(a[mid]>=a[0])
        s=mid+1;
        else
        e=mid;
    }
    return s;
}

long long binarySearch(long long a[], long long s, long long e, long long d){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==d)
        return mid+1;
        if(a[mid]<d)
        s=mid+1;
        else
        e=mid-1;
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    int n,k; cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int p=pivot(a,0,n-1);
    if(k>=a[p]&&k<=a[n-1])
    cout<<binarySearch(a,p,n-1,k);
    else
    cout<<binarySearch(a,0,p-1,k);
}