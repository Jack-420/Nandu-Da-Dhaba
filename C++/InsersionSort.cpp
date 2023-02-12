#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    int t;
    cin>>t;
    while(t--) {
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            int key=a[i];
            int j=i-1;
             while (j >= 0 && arr[j] > key) {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=key;
        }
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<"\n";1
    }
}