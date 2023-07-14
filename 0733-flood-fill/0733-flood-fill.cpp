class Solution {
private:
    void dfs(vector<vector<int>>& image,vector<vector<int>>&vis, int row,int col, int color ,int ini){
        vis[row][col]=1;
        image[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini && !vis[nrow][ncol]) {
                dfs(image,vis,nrow,ncol,color,ini);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ini=image[sr][sc];
        dfs(image,vis,sr,sc,color,ini);
        return image;
    }
};