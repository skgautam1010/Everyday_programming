

/*Swap Nodes in Pairs
Medium

Given a linked list, swap every two adjacent nodes and return its head.

 

Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [1]
Output: [1]
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode *temp=head;
        vector<int>v;
        
        while(temp!=nullptr)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        for(int i=0;i<n-1;i=i+2)
        {
            swap(v[i],v[i+1]);
        }
        
        
        ListNode *l=new ListNode(-1);
        ListNode *k=l;
        for(int i=0;i<n;i++)
        {
            ListNode *x=new ListNode(v[i]);
            k->next=x;
            k=k->next;
        }
        return l->next;
        
        
    }
};