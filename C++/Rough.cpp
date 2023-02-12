class Solution {
public:
    long long dfs(long long node, long long n, unordered_map<long long,list<pair<long long,long long>>> &adj, 
    unordered_map<long long,bool> &vis, vector<long long>& minDis,vector<long long>& ways){
        vis[node]=true;
        if(minDis[node]!=INT_MAX) return ways[node];
        if(node==n-1){
            vis[node]=false;
            return 1;
        }
        long long ans=0;
        for(auto i:adj[node]){
            long long newNode=i.first;
            long long newDis=i.second;
            if(!vis[newNode]){
                long long temp=dfs(newNode,n,adj,vis,minDis,ways);
                if(minDis[newNode]!=INT_MAX&&minDis[newNode]+newDis<minDis[node]){
                    minDis[node]=minDis[newNode]+newDis;
                    ans=temp;
                }
                else if(minDis[newNode]!=INT_MAX&&minDis[newNode]+newDis==minDis[node]){
                    ans+=temp;
                }
            }
        }
        vis[node]=false;
        ways[node]=ans;
        return ans;
    }
    int  countPaths(int  n, vector<vector<int >>& roads) {
        unordered_map<long long,bool> vis;
        unordered_map<long long,list<pair<long long,long long>>> adj;
        for(auto i: roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<long long> minDis(n,INT_MAX);
        vector<long long> ways(n,0);
        ways[n-1]=1;
        minDis[n-1]=0;
        long long ans=dfs(0,n,adj,vis,minDis,ways);
        return ans;
    }
};