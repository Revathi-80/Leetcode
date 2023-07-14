class Solution {
private:
    void dfs(vector<int>adj[],vector<int>&vis, int node){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(201,0);
        int cnt=0;
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};