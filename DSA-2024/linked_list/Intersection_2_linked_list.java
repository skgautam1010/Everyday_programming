/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {


        //Brute force TC : O(N*N)
       if(headA==null || headB==null)
       {
        return null;
       }
       ListNode tempA=headA;
       
       while(tempA!=null)
       {
        ListNode tempB=headB;
        while(tempB!=null)
        {
             if(tempA==tempB)
            {
                return tempA;
            }
            tempB=tempB.next;
        }
       
        tempA=tempA.next;
        
       }


       return null;
    }
}