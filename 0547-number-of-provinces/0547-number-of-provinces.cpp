class Solution {
    void dfs(int node,vector<int>adj[],int vis[]) {
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v= isConnected.size();
        vector<int>adj[v];
        for(int i=0;i<v;i++) {
            for(int j=0;j<v;j++) {
                if(i!=j && isConnected[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        int vis[200]={0};
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};