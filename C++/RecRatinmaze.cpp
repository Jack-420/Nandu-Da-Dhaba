#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool isSafe(int x, int y, vector<vector<int>> v, int n, vector<vector<int>> a){
    if((x>=0&&x<=n-1)&&(y>=0&&y<=n-1)&&v[x][y]==0&&a[x][y]==1)
    return true;
    return false;
}

void solve(vector<vector<int>> a, int n, vector<string>& ans, int x, int y, vector<vector<int>> v, string path){
    if(x==n-1&&y==n-1){
        ans.push_back(path);
        return ;
    }
    v[x][y]=1;
    // down
    int newx=x+1;
    int newy=y;
    if(isSafe(newx,newy,v,n,a)){
        path.push_back('D');
        solve(a,n,ans,newx,newy,v,path);
        path.pop_back();
    }
    // up
    newx=x-1;
    newy=y;
    if(isSafe(newx,newy,v,n,a)){
        path.push_back('U');
        solve(a,n,ans,newx,newy,v,path);
        path.pop_back();
    }
    // Right
    newx=x;
    newy=y+1;
    if(isSafe(newx,newy,v,n,a)){
        path.push_back('R');
        solve(a,n,ans,newx,newy,v,path);
        path.pop_back();
    }
    // Left
    newx=x;
    newy=y-1;
    if(isSafe(newx,newy,v,n,a)){
        path.push_back('L');
        solve(a,n,ans,newx,newy,v,path);
        path.pop_back();
    }
    v[x][y]=0;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420
    // #define int long long

    int n; cin>>n;
    int g[n][n];
    vector<vector<int>> a(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>g[i][j];
        a[i][j]=g[i][j];
    }
    vector<string> ans;
    vector<vector<int>> v(n,vector<int> (n,0));
    string path="";
    solve(a,n,ans,0,0,v,path);
    sort(ans.begin(),ans.end());
    if(a[0][0]==0)
    cout<<-1;
    else
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<"\n";
}