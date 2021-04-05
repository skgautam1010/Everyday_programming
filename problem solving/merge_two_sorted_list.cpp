
/*Merge Two Sorted Lists
Easy

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Input: l1 = [], l2 = []
Output: []

Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

 */

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result=new ListNode(-1);
        ListNode *temp=l1;
        ListNode *temp1=l2;
        ListNode *p=result;
       
        while(temp!=NULL && temp1!=NULL)
        {
            if(temp->val<=temp1->val)
            {
                ListNode *value=new ListNode(temp->val);
                p->next=temp;
                p=p->next;
                temp=temp->next;
            }
            else
            {
                ListNode *value2=new ListNode(temp1->val);
                p->next=temp1;
                p=p->next;
                temp1=temp1->next;
            }
        }
        
        while(temp!=NULL)
        {
            ListNode *value=new ListNode(temp->val);
                p->next=temp;
                p=p->next;
                temp=temp->next;   
        }
        while(temp1!=NULL)
        {
            ListNode *value2=new ListNode(temp1->val);
                p->next=temp1;
                p=p->next;
                temp1=temp1->next;
        }
        return result->next;
    }
};