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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>cnt;
        vector<TreeNode*>res;
        function<string(TreeNode*)>traverse = [&cnt,&res,&traverse] (TreeNode* node) -> string {
            if(node== NULL) {
                return "";
            }
            string rep = "(" + traverse(node->left) +")" + to_string(node->val) +"(" + traverse(node->right) +")";
            cnt[rep]++;
            if(cnt[rep]==2) {
                res.push_back(node);
            }
            return rep;
        };
        traverse(root);
        return res;
    }
};