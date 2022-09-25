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
    private:
    void allPaths(TreeNode* root,int targetSum,vector<vector<int>>&ans, vector<int>temp){
     
        if(root==NULL)
            return ;
        if(!root->right && !root->left && targetSum==root->val){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        allPaths(root->left,targetSum-root->val,ans,temp);
        allPaths(root->right,targetSum-root->val,ans,temp);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        allPaths(root,targetSum,ans,{});
        return ans;
    }
};