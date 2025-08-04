class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0, left = 0, right = col - 1, bottom = row - 1;
        // right = 3, bottom = 2
        vector<int> ans;

        while (top <= bottom && left <= right) {
            // 0 -> 3: 1 2 3 4
            // 1 -> 2: 6 7
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            // 1
            // 2
            top++;
            // 1 -> 2: 8 12
            // 2 -> 1 x
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            // 2
            // 1
            right--;
            // 3 -> 0: 11, 10, 9
            // 1 -> 1: 6 x
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
            }
            // 1
            // 0
            bottom--;
            // 1 -> 1: 5
            // 0 -> 2 x
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }
            // 1
            // 2
            left++;
        }
        return ans;
    }
};