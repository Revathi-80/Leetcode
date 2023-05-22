class Solution {
private:
    bool check(int start,vector<vector<int>>& graph,int color[],int col){
       
        color[start]=col;
        
            for(auto it: graph[start]){
                if(color[it]==-1) {
                    if(check(it,graph,color,!col)==false) return false;
                }
                else if(color[it]==col)
                    return false;
            }
        return true;
    }    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        for(int i=0;i<n;i++) color[i]=-1;
        for(int i=0;i<n;i++) {
            if(color[i]==-1) {
                if(check(i,graph,color,0)==false)
                    return false;
            }
        }
        return true;
    }
};