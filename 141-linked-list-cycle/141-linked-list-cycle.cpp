/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       // int cnt=0;
        if( head==NULL || head->next==NULL)
            return false;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
           // cnt++;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) {
             //   cout<<cnt;
                return true;
            }
        }
        return false;
    }
};