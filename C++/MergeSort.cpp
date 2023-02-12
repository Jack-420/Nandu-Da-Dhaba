#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void merge(int a[], int s, int e){
    int mid=s+(e-s)/2;
    int len1=mid+1-s;
    int len2=e-mid;
    int first[len1];
    int second[len2];
    // copy value
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=a[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){ 
        second[i]=a[k++];
    }
    // merge 2 sorted array
    int ind1=0;
    int ind2=0;
    k=s;
    while(ind1<len1&&ind2<len2){
        if(first[ind1]<second[ind2]){
            a[k++]=first[ind1++];
        } else {
            a[k++]=second[ind2++];
        }
    }
    while(ind1<len1){
        a[k++]=first[ind1++];
    }
    while(ind2<len2){
        a[k++]=second[ind2++];
    }
}

void mergeSort(int a[], int s, int e){
    if(s>=e)
    return;
    int mid=s+(e-s)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    merge(a,s,e);
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
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}