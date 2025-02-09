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

   


   //optimal approach
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //ListNode temp1 = l1; ListNode temp2 = l2;
        ListNode dummyNode = new ListNode(-1);
        ListNode temp = dummyNode;
        int carry = 0;
        int res = 0;
        while(l1 != null || l2 != null) {

            res = carry;
            
            if(l1 != null) {
                res = res + l1.val;
                l1 = l1.next;
            }
            if(l2 != null) {
                res = res + l2.val;
                l2 = l2.next;
            }
            if(res<10) {
                carry = 0;
            }
            else { 
                carry = 1;
                res = res - 10;
            }
            

            ListNode newNode = new ListNode(res);
            temp.next = newNode;
            temp = newNode;

        }

        if(carry == 1) {
             ListNode newNode = new ListNode(carry);
            temp.next = newNode;
            temp = newNode;
        }
        
        
        
        return dummyNode.next;
    }

    
}