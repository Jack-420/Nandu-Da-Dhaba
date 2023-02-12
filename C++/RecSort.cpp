#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void BubbleSort(int a[], int n){
    if(n==0||n==1)
    return ;
    for(int i=0;i<n-1;i++)
    if(a[i]>a[i+1])
    swap(a[i],a[i+1]);
    BubbleSort(a,n-1);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    // #define int long long

    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    BubbleSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}