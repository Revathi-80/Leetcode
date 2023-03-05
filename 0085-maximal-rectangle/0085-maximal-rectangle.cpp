class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m= matrix[0].size(),ans=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                for(int row=i,colLen=m,col;row<n && matrix[row][j]=='1'; row++) {
                    for(col=j;col<m && matrix[row][col]=='1';col++);
                    colLen = min(colLen,col-j);
                    ans= max(ans,(row-i+1)*colLen);
                }
            }
        }
        return ans;
    }
};