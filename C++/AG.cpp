#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int pos(int a[], int mid, int m){
    sort(a.begin(),a.end());
    int lc=a[0],cnt=1;
    for(int i=0;i<n;i++){
        if(a[i]-lc>=mid){
            cnt++;
            lc=a[i];
        }
        if(cnt==m)
        return 1;
    }
    return 0;
}


int agCow(int a[], int s, int e, int m){
    int mid=s+(e-s)/2,ans=-1;
    while(s<=e){
        if(pos(a,mid,m)){
            ans=mid;
            s=mid+1;
        } else {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
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
        int n,m,maxi=-1; cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++){ 
            cin>>a[i];
            if(a[i]>maxi)
            maxi=a[i];
        }
        cout<<agCow(a,0,maxi-a[0],m);
    }
}