/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{  
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent) {
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* current=queue.front();
            queue.pop();
            if(current->left){
                parent[current->left]=current;
                queue.push(current->left);
            }
            if(current->right) {
                parent[current->right]=current;
                queue.push(current->right);
            }
        }
    }
    
    public:
        vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
        {
           unordered_map<TreeNode*,TreeNode*>parent;
            markParents(root,parent);
            
            unordered_map<TreeNode*,bool>visited;
            queue<TreeNode*>q;
            q.push(target);
            visited[target]=true;
            int cnt=0;
            while(!q.empty()) {
                int size=q.size();
                if(cnt ==k )
                    break;
                cnt++;
                for(int i=0;i<size;i++) {
                    TreeNode* cur=q.front();
                    q.pop();
                    TreeNode* upper=parent[cur];
                    
                    if(cur->left && !visited[cur->left]) {
                        q.push(cur->left);
                        visited[cur->left]=true;
                    }
                    if(cur->right && !visited[cur->right]) {
                        q.push(cur->right);
                        visited[cur->right]=true;
                    }
                    if(upper && !visited[upper]){
                        q.push(upper);
                        visited[upper]=true;
                    }
                }
            }
            vector<int>ans;
            while(!q.empty()){
                TreeNode* temp=q.front();
                q.pop();
                ans.push_back(temp->val);
            }
            
            return ans;
        }
};