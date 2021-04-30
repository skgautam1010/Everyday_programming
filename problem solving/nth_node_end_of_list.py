'''Remove Nth Node From End of List
Medium

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        temp =head
        p=head
        count=1
        if not head.next and n==1:
            return None
        
        if head.next.next is None:
            if n==1:
                head.next=None
                return head
            elif n==2:
                head=head.next
                return head
            
        
        while p.next is not None:
            count +=1
            p=p.next
            
        if count==n:
            head=head.next
            return head
            
        elem_rem=count-n
        i=1
        while i<elem_rem:
            i +=1
            temp=temp.next
        
        temp.next=temp.next.next
        
        return head