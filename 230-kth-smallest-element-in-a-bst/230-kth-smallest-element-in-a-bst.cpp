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
   int kthSmallest(TreeNode* root, int k) {
     vector<TreeNode*> stac(k);
    int i = 0, j = k;
    while (true) {
        while (root) {
            stac[i++%k] = root;
            root = root->left;
        }
        root = stac[--i%k];
        if (! --j)
            return root->val;
        root = root->right;
    }
}
};