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

    //Best Approach TC: O(N)

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
       if(headA==null || headB==null)
       {
        return null;
       }
       
       ListNode tempA=headA;
       ListNode tempB = headB;
       while(tempA!=tempB) {
            tempA=tempA.next;
            tempB=tempB.next;

            if(tempA==tempB) {
                return tempA;
            }
            if(tempA== null) {
                tempA=headB;
            }
            if(tempB==null) {
                tempB=headA;
            }
       }
       return tempA;
       
       
    }

    //Optimized Approach

    public ListNode collideNode(ListNode largerNode,ListNode smallerNode, int d) {
       while(d!=0) {
        d--;
        largerNode = largerNode.next;
       }
       while(largerNode!=smallerNode) {
        largerNode=largerNode.next;
        smallerNode=smallerNode.next;
       }
       return smallerNode;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
       if(headA==null || headB==null)
       {
        return null;
       }
       
       ListNode tempA=headA;
       ListNode tempB = headB;
       int size1 = 0;
       int size2 = 0;
       while(tempA!=null) {
        size1++;
        tempA=tempA.next;
       }
       while(tempB!= null) {
        size2++;
        tempB= tempB.next;
       }
       if(size1>size2) {
            return collideNode(headA,headB,(size1-size2));
       }
       else if(size2>size1) {
        return collideNode(headB,headA,(size2-size1));
       }
       else {
        return collideNode(headA,headB,0);
       }
       
       
    }



    //Brute force approach 
    public boolean find(ListNode temp,List<ListNode>data) {
        for(ListNode val : data) {
            if(val==temp) {
                return true;
            }
        }
        return false;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
       if(headA==null || headB==null)
       {
        return null;
       }
       
       ListNode tempA=headA;
       
       ListNode tempB = headB;
       List<ListNode> store = new LinkedList<>();
       while(tempA!= null) {
        store.add(tempA);
        tempA=tempA.next;
       }
    
       while(tempB!= null) {
        boolean result = find(tempB,store);
        if(result) {
            return tempB;
        }    
        tempB = tempB.next;
       }
       return null;
    }
}