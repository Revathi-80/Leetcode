class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows=mat.size();
        int col=mat[0].size();
        if((rows*col)!=(r*c)) return mat;
        vector<vector<int>>vec(r,vector<int>(c));
        int new_row=0,new_col=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                vec[new_row][new_col]=mat[i][j];
                new_col++;
                if(new_col==c){
                 new_col=0;
                    new_row++;
                }
            }
        }
        return vec;
    }
};