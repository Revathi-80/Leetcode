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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q; // node,index
        q.push({root,0}); // initially push the root with index 0
        while(!q.empty()){
            int min=q.front().second;
            int size=q.size();
            int start,end;
            for(int i=0;i<size;i++){
                int cur=q.front().second - min;
                TreeNode* node= q.front().first;
                q.pop();
                if(i==0) 
                    start=cur;
                if(i==size-1)
                    end=cur;
                if(node->left)
                    q.push({node->left,(long long)2*cur+1});
                if(node->right)
                    q.push({node->right,(long long)2*cur+2});
                
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};