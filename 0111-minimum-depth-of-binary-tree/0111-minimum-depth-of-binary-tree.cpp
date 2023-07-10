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
    int depth(TreeNode* root) {
        if(root==NULL) return  0;
        int lh= depth(root->left);
        int rh= depth(root->right);
        if(root->left && root->right)
        return 1+min(lh,rh);
        else
            return 1+max(lh,rh);
    }
public:
    int minDepth(TreeNode* root) {
        return depth(root);
    }
};