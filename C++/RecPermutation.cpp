#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(vector<int> v, int ind, vector<vector<int>>& ans){
    if(ind==v.size()){
        ans.push_back(v);
        return;
    }
    for(int i=ind;i<v.size();i++){
        swap(v[ind],v[i]);
        solve(v,ind+1,ans);
        swap(v[ind],v[i]);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    // #define int long long

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> ans;
    solve(v,0,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }   
}