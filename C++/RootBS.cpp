#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

long long binarySearch(long long s, long long e, long long d){
    int ans=1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid*mid==d){
            return mid;
        }else if(mid*mid>d){
            e=mid-1;
        }else{
            ans=mid;
            s=mid+1;
        }
    }
    return ans;
}

double presision(long long n, long long pres, long long temp){
    double factor=1;
    double ans=temp;
    for(int i=0;i<pres;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j+=factor)
        ans=j;
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

    int n; cin>>n;
    cout<<presision(n,5,binarySearch(0,n/2,n));
}