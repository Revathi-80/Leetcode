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
class Solution {
    void swapH(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return ;
        swap(head->val,head->next->val);
        swapH(head->next->next);
    }
public:
    ListNode* swapPairs(ListNode* head) {
        swapH(head);
        return head;
    }
};