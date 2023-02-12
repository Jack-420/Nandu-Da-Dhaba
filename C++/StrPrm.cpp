#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(string& s, int Ind, vector<string>& ans){
    if(Ind==s.size()){
        ans.push_back(s);
        return ;
    }
    for(int i=Ind;i<s.size();i++){
        swap(s[Ind],s[i]);
        solve(s,Ind+1,ans);
        swap(s[Ind],s[i]);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    #define int long long

    string s; cin>>s;
    int Ind=0;
    vector<string> ans;
    solve(s,Ind,ans);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";
}