/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int count(ListNode *head) {
        if(!head)
            return 0;
        return 1+count(head->next);
    }
    TreeNode *BST(ListNode* &head,int n) {
        if(n<=0)
            return NULL;
        TreeNode *leftnode=BST(head,n/2);
        TreeNode *root= new TreeNode(head->val);
        head=head->next;
        root->left=leftnode;
        
        root->right = BST(head,n-n/2-1);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n=count(head);
        return BST(head,n);
    }
};