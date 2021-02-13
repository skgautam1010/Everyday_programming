 /*Add Two Numbers
Medium

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyhead=new ListNode(-1);
        ListNode *l=dummyhead;
        int carry=0;
        
        while(l1!=NULL|| l2!=NULL)
        {
            int sum=carry;
            if(l1!=NULL)
            {
                sum +=l1->val;
                l1=l1->next;
                
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            l->next=new ListNode(sum%10);
            l=l->next;
            carry=sum/10;
        }
        if(carry!=0)
        {
            l->next=new ListNode(carry);
        }
        return dummyhead->next;
        
    }
};