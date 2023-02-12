#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool Possible(long long a[],long long n, long long m, long long mid) {
    int student=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+a[i]<=mid){
            sum+=a[i];
        } else {
            student++;
            if(student>m||a[i]>mid){
                return false;
            }
            sum=a[i];
        }
    }
    return true;
}

long long AllocateBook(long long a[], long long n, long long s, long long e,long long m) {
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(Possible(a,n,m,mid)){
            ans=mid;
            e=mid-1;
        } else {
            s=mid+1;
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
        int n,m; cin>>n>>m;
        int a[n],sum=0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            sum+=a[i];
        }
        cout<<AllocateBook(a,n,0,sum,m);
    }
}