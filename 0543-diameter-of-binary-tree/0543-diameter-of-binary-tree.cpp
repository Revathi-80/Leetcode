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
    int findMax(TreeNode* root, int& maxi) {
        if(root==0) return 0;
        int lh=findMax(root->left,maxi);
        int rh=findMax(root->right,maxi);
        maxi=max(lh+rh,maxi);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        int h=findMax(root,maxi);
        return maxi;
    }
};