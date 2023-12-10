
/*
Reverse Nodes in k-Group
Hard

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

    Could you solve the problem in O(1) extra memory space?
    You may not alter the values in the list's nodes, only nodes itself may be changed.

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]

Example 4:

Input: head = [1], k = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is in the range sz.
    1 <= sz <= 5000
    0 <= Node.val <= 1000
    1 <= k <= sz

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
    /*vector<int> reverse(vector<int>arr)
    {
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j)
        {
            swap(arr[i],arr[j]);
            i++;j--;
        }
        return arr;
    }*/
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        if(k==1)
        {
            return head;
        }
        vector<int>v;
        ListNode *temp=head;
        while(temp!=nullptr)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        if(k==2)
        {
            for(int i=0;i<n-1;i=i+k)
            {
                swap(v[i],v[i+1]);
            }
        }
        else if(k==n)
        {
           reverse(v.begin(),v.end()); 
        }
        else
        {
            
            for(int i=0;i<n;i=i+k)
            {
                if((i+k)<=n)
                {
                    reverse(v.begin()+i,v.begin()+k+i);
                }
                else if(i<n)
                {
                    std::reverse(arr.begin()+i,arr.end());
                }
            }
        }
        ListNode *l=new ListNode(-1);
        ListNode *m=l;
        for(int i=0;i<n;i++)
        {
            ListNode *x=new ListNode(v[i]);
            m->next=x;
            m=m->next;
        }
        return l->next;
        
        
        
        
    }
};