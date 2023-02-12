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

    int t; cin>>t;
    while(t--) {
        int n,m; cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin>>a[i][j];
        int sr=0,sc=0,er=n-1,ec=m-1;
        int tt=n*m,count=0;
        while(count<tt){
            for(int i=sc;count<tt&&i<=ec;i++)
            cout<<a[sr][i]<<" ";          
            count+=ec-sc+1;
            sr++;
            for(int i=sr;count<tt&&i<=er;i++)
            cout<<a[i][ec]<<" ";
            count+=er-sr+1;
            ec--;
            for(int i=ec;count<tt&&i>=sc;i--)
            cout<<a[er][i]<<" ";
            count+=sc-ec+1;
            er--;
            for(int i=er;count<tt&&i>=sr;i--)
            cout<<a[i][sc]<<" ";            
            count+=sr-er+1;
            sc++;
        }
    }
}