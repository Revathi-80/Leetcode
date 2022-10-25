class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int s=0,e=col-1;
        while(s<row && e>=0){
            int curr= matrix[s][e];
            if(curr==target)
                return true;
            else if(curr>target)
                e--;
            else
                s++;
        }
        return false;
    }
};