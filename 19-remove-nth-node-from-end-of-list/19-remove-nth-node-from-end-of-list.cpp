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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode *temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int k=cnt-n;
        int ind=1;
      //  cout<<cnt<<" "<<k<<endl;
        ListNode *del=new ListNode();
        del->next=head;
        ListNode *node=del;
        while(ind<=k ){
            node=node->next;
           // cout<<node->val<<endl;
            ind++;
        }
        node->next=node->next->next;
        return del->next;
    }
};