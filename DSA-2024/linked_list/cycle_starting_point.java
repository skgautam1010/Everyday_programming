public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null || head.next==null)
        {
            return null;
        }
        //Optimal Approach
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null)
        {
            fast=fast.next.next;
            slow=slow.next;
            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow=slow.next;
                    fast=fast.next;
                }
                return slow;
            }
        }
        //Brute Force
        /*HashMap<ListNode,Integer>visited=new HashMap<>();
        ListNode temp=head;
        while(temp!=null)
        {
            if(visited.containsKey(temp))
            {
                return temp;
            }
            visited.put(temp,1);
            temp=temp.next;
        }*/
        return null;
    }
}