#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(int a[], int n, vector<int> o, int Ind, vector<vector<int>>& ans){
    if(Ind>=n){
        ans.push_back(o);
        return ;
    }
    solve(a,n,o,Ind+1,ans);
    o.push_back(a[Ind]);
    solve(a,n,o,Ind+1,ans);
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    // #define int long long

    int n,Ind=0; cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> o;
    vector<vector<int>> ans;
    solve(a,n,o,Ind,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }    
        cout<<endl;
    }
}