#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(string s, string o, int Ind, vector<string>& ans){
    if(Ind>=s.size()){
        ans.push_back(o);
        return ;
    }
    solve(s,o,Ind+1,ans);
    o.push_back(s[Ind]);
    solve(s,o,Ind+1,ans);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    string s; cin>>s;
    vector<string> ans;
    string o="";
    int Ind=0;
    solve(s,o,Ind,ans);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";
}