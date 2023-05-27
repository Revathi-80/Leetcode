/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void Path(TreeNode* root,vector<int>&ds,vector<vector<int>>&ans,int targetSum,int sum) {
        if(root== NULL) return;
        sum+=root->val;
        ds.push_back(root->val);
        if(root->left==NULL && root->right==NULL) {
            if(sum==targetSum)
                ans.push_back(ds);
            }
        else {
                Path(root->left,ds,ans,targetSum,sum);
                Path(root->right,ds,ans,targetSum,sum);
            }
        
        ds.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ds;
        vector<vector<int>>ans;
        int sum=0;
        Path(root,ds,ans,targetSum,sum);
        return ans;
    }
};