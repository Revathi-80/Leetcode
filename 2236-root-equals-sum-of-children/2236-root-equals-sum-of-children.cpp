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
public:
    bool checkTree(TreeNode* root) {
        if (root==NULL)
            return true;
        int child=0;
        if(root->left) child+=root->left->val;
        if(root->right) child+=root->right->val;
        if(child!=root->val)
            return false;
        checkTree(root->left);
        checkTree(root->right);
        return true;
    }
};