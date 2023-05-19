class Solution {
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>rows(row,0);
        vector<int>cols(col,0);
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(matrix[i][j]!=0) {
                    if(rows[i]==1 || cols[j]==1) {
                        matrix[i][j]=0;
                    }
                }
            }
        }
    }
};