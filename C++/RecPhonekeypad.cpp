#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void solve(string s, string out, string a[], int ind, vector<string>& ans){
    if(ind==s.size()){
        ans.push_back(out);
        return;
    }
    int num=s[ind]-'0';
    string value=a[num];
    for(int i=0;i<value.size();i++){
        out+=value[i];
        solve(s,out,a,ind+1,ans);
        out.pop_back();
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
    vector<string> ans;
    string a[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string out;
    solve(s,out,a,0,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}