class Solution {
    void dfs(vector<vector<int>> &isConnected, vector<int> &vis, int u, int nodes) {
        // cout<<u<<" ";
        vis[u]=1;
        for(int v=0; v<nodes; v++) {
            if(u!=v && isConnected[u][v]==1) {
                if(!vis[v]) {
                    dfs(isConnected, vis, v, nodes);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // int n=isConnected.size();
        // int m=isConnected[0].size();
        // int cnt=0;
        // vector<vector<int>>vis(n,vector<int>(m,0));
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         if(vis[i][j]!=0 && isConnected[i][j]==1) {
        //             cnt++;
        //             dfs(isConnected,vis,i,j);
        //         }
        //     }
        // }
        // return cnt;
        int nodes = isConnected.size();
        vector<int> vis(nodes, 0);
        int cnt=0;
        for(int i=0; i<nodes; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(isConnected, vis, i, nodes);
            }
            
        }
        
        return cnt;
    }
};