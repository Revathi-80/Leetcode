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
    int minTime(TreeNode* start,map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        q.push(start);
        map<TreeNode*,int>vis;
        vis[start]=1;
        int time=0;
        while(!q.empty()){
            int fl=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                vis[node]=1;
                q.pop();
                //left
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=1;
                    fl=1;
                }
                //right
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=1;
                    fl=1;
                }
                //top
                if(mp[node] && !vis[mp[node]]){
                    q.push(mp[node]);
                    vis[mp[node]]=1;
                    fl=1;
                }
            }
            if(fl)
            time++;
        }
        return time;
        
    }
    TreeNode * bfsParent(TreeNode* root, int target, map<TreeNode*,TreeNode*>&mp) {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node=q.front();
            if(node->val==target) res=node;
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left]=node;
            }
            if(node->right) {
                q.push(node->right);
                mp[node->right]=node;
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mp;
        TreeNode* target=bfsParent(root,start,mp);
        int maxi=minTime(target,mp);
        return maxi;
    }
};