#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int linerSearch(int a[], int n, int k){
    if(n==0)
    return 0;
    if(a[0]==k)
    return 1;
    else 
    return linerSearch(a+1,n-1,k);
}

int binarySearch(int a[], int s, int e, int k){
    if(s>e)
    return 0;
    int mid = s+(e-s)/2;
    if(a[mid]==k)
    return 1;
    if(a[mid]<k)
    return binarySearch(a,mid+1,e,k);
    return binarySearch(a,s,mid-1,k);
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    // #define int long long

    int n,k; cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    // cout<<linerSearch(a,n,k)<<"\n";
    if(binarySearch(a,0,n-1,k))
    cout<<"Found\n";
    else
    cout<<"NOt Found\n";
}