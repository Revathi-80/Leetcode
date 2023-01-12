class Solution {
    int dfs(int node, int parent, vector<vector<int>>&adj, vector<bool>&hasApple) {
        int totaltime=0, childTime=0;
        for(auto child : adj[node]) {
            if(child==parent) continue;
            childTime=dfs(child,node,adj,hasApple);
            if(childTime || hasApple[child])
                totaltime +=childTime+2;
        }
        return totaltime;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto edge :edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
        }
        return dfs(0,-1,adj,hasApple);
    }
};