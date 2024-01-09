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
    void Traversal(TreeNode *root1, vector<int>&ans) {
        if(root1==NULL) {
            return;
        }
        if(root1->left==NULL && root1->right==NULL)
         ans.push_back(root1->val);
       Traversal(root1->left,ans);
       Traversal(root1->right,ans);

    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>ans1,ans2;
        Traversal(root1,ans1);
        Traversal(root2,ans2);
        return ans1==ans2;

    }
};