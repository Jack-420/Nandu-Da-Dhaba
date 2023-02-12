#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

void solve(vector<int> v, vector<int> out, int ind, vector<vector<int>>& ans){
	if(ind==v.size()){
		ans.push_back(out);
		return;
	}
	solve(v,out,ind+1,ans);
	out.push_back(v[ind]);
	solve(v,out,ind+1,ans);
}


int32_t main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		jack420

	int n; cin>>n;
	vector<int> v(n),out;
	for(int i=0;i<n;i++) cin>>v[i];
	vector<vector<int>> ans;
	solve(v,out,0,ans);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++) 
		cout<<ans[i][j]<<" ";
		cout<<"\n";
	}
}