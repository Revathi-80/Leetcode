class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>front(n);
        for(int j=0;j<n;j++){
            front[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--) {
            vector<int>curr(n);
            for(int j=i;j>=0;j--) {
                curr[j]=triangle[i][j]+min(front[j],front[j+1]);
            }
            front=curr;
        }
        return front[0];
    }
};