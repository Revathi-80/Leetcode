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
 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* temp=new ListNode();
        ListNode *temp1=temp,*p=l1,*q=l2;
        int carry=0,sum=0;
        while(p!=NULL || q!=NULL ){
            int x=(p!=NULL) ?p->val:0;
            int y=(q!=NULL) ?q->val:0;
            int sum=x+y+carry;
            carry=(sum>=10)?1:0;
            sum=sum%10;
            temp1->next=new ListNode(sum);
            temp1=temp1->next;
            if(p!=NULL)
            p=p->next;
            if(q!=NULL)
            q=q->next;
        }
        if(carry>0)
            temp1->next=new ListNode(carry);
        return temp->next;
    }
};