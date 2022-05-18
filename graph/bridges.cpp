class Solution {
public:
    vector<int>tin,low,vis; 
    vector<vector<int>>adj,res;
    void dfs(int node,int parent,int&timer){
        vis[node] = 1; 
        tin[node] = low[node] = timer++; 
        for(auto it: adj[node]) {
            if(it == parent) continue;
            if(!vis[it]) {
                dfs(it, node,timer); 
                low[node] = min(low[node], low[it]); 
                if(low[it] > tin[node]) {
                    res.push_back({node,it});
                }
            } else {
                low[node] = min(low[node], tin[it]); 
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vis.resize(n,0);
        low.resize(n,-1);
        tin.resize(n,-1);
        adj.resize(n);
        for(auto i:c){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int timer = 0; 
        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                dfs(i, -1,timer); 
            }
        }
        return res;
    }
};
