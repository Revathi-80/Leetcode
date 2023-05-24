class Solution {
private:
    void dfs(int row,int col,int color,int iniColor,vector<vector<int>>&ans, vector<vector<int>>&image, int dr[],int dc[] ){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && ans[nrow][ncol]!=color && image[nrow][ncol]==iniColor){
                dfs(nrow,ncol,color,iniColor,ans,image,dr,dc);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int iniColor=image[sr][sc]; 
      int n=image.size();
      int m=image[0].size();
      vector<vector<int>>ans=image;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
      dfs(sr,sc,color,iniColor,ans,image,dr,dc);
        return ans;
        
    }
};