#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(string s, vector<string>& ans, string o, int Ind, string m[]){
    if(Ind>=s.size()){
        ans.push_back(o);
        return ;
    }
    int num = s[Ind]-'0';
    string value = m[num];
    for(int i=0;i<value.size();i++){
        o.push_back(value[i]);
        solve(s,ans,o,Ind+1,m);
        o.pop_back();
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    // #define int long long

    string s,o; cin>>s;
    vector<string> ans;
    int Ind=0;
    string m[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(s,ans,o,Ind,m);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";
}