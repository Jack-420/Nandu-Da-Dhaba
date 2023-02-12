#include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define jack420 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define int long long
template <typename T> 

class graph{
    public:
    map<T,list<T>> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(!direction)
        adj[v].push_back(u);
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
};


vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        ans[i].push_back(i);
    }
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    return ans;
}

void prepareAdj(unordered_map<int,set<int>> &adj, vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int i){
    queue<int> q;
    q.push(i);
    visited[i]=true;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto j:adj[frontNode]){
            if(!visited[j]){
                q.push(j);
                visited[j]=true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> &edges){
    unordered_map<int,set<int>> adj;
    unordered_map<int,bool> visited;
    vector<int> ans;
    prepareAdj(adj,edges); 
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
    }
    return ans;
}


int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        jack420

    int n,m; cin>>n>>m;
    graph<int> g;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g.addEdge(u,v,false);
    }
    g.print();
}