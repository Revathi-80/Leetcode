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
bool hasPath(TreeNode* root,int target,int sum) {
    if(root == NULL ) return false;
       if(root->left==NULL && root->right==NULL) {
           sum=sum+root->val;
           if(sum==target)
         return true;
       }
        int lh = hasPath(root->left,target,sum+root->val);
        int rh = hasPath(root->right,target,sum+root->val);
      return lh || rh;
}
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return hasPath(root,targetSum,sum);
    }
};