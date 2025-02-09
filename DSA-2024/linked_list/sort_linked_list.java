/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
     public ListNode mergeTwoList(ListNode left,ListNode right)
    {
        ListNode new_head=new ListNode(-1);
        ListNode temp=new_head;
        while(left!=null && right!=null)
        {
            if(left.val<=right.val)
            {
                temp.next=left;
                left=left.next;
            }
            else
            {
                temp.next=right;
                right=right.next;
            }
            temp=temp.next;
        }
        while(left!=null)
        {
            temp.next=left;
            left=left.next;
            temp=temp.next;
        }
        while(right!=null)
        {
            temp.next=right;
            right=right.next;
            temp=temp.next;
        }
        return new_head.next;
    }
    public ListNode middleNode(ListNode head)
    {
         if(head==null || head.next==null)
        {
            return head;
        }
        ListNode fast=head.next;
        ListNode slow=head;
        while(fast!=null && fast.next!=null)
        {

            fast=fast.next.next;
            slow=slow.next;
        }
        return slow;
    }
  
        
        
    }
    public ListNode sortList(ListNode head) {
        //optimal approach
        if(head==null || head.next==null)
        {
            return head;
        }
        ListNode middle=middleNode(head);
        ListNode right=middle.next;
        middle.next=null;
        ListNode left=head;
        left=sortList(left);
        right=sortList(right);
        return mergeTwoList(left,right);


        //Brute Force Approach
        ArrayList<Integer> ar=new ArrayList<>();
        ListNode temp=head;
        while(temp!=null)
        {
            ar.add(temp.val);
            temp=temp.next;
        }
        Collections.sort(ar);
        temp=head;
        int i=0;
        while(temp!=null)
        {
            temp.val=ar.get(i);
            i++;
            temp=temp.next;
        }
        return head;
    }
}