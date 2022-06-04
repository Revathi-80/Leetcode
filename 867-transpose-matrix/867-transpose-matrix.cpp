class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>>mat(cols,vector<int>(rows));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mat[j][i]=matrix[i][j];
            }
        }
        return mat;
    }
};