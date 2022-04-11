class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int new_j=(j+k)%m;
                int new_i=(i+(j+k)/m)%n;
                ans[new_i][new_j]=grid[i][j];
            }
        }
        return ans;
    }
};