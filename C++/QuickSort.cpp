#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int Partition(int a[], int s, int e){
    int pivot=a[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++)
        if(a[i]<=pivot)
            cnt++;
    int pivotInd=s+cnt;
    swap(a[s],a[pivotInd]);
    int i=s,j=e;
    while(i<pivotInd&&j>pivotInd){
        if(a[i]<=pivot)
            i++;
        else if(a[j]>pivot)
            j--;
        else {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    return pivotInd;
}

void QuickSort(int a[], int s, int e){
    if(s>=e)
    return ;
    int p=Partition(a,s,e);
    QuickSort(a,s,p-1);
    QuickSort(a,p+1,e);
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
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}