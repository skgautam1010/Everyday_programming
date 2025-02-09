class Solution {
    public ListNode reverse(ListNode head)
    {
        ListNode prev=null;
        ListNode slow=head;
        ListNode current=slow;
        while(slow!=null)
        {
            slow=slow.next;
            current.next=prev;
            prev=current;
            current=slow;
        }
        return prev;
    }
    public boolean isPalindrome(ListNode head) {

        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;

        }
        ListNode newHead=reverse(slow);
        ListNode first_node=head;
        List second_node=newHead;
        while(second_node!=null)
        {
            if(first_node.val!=second_node.val)
            {
                reverse(newHead);
                return false;
            }
            first_node=first_node.next;
            second_node=second_node.next;
        }
        reverse(newHead);
        return true;
        //Brute Force Approach
        ListNode reverse=head;
        ListNode temp=head;
        Stack<Integer>st=new Stack<>();
        while(temp!=null)
        {
            st.push(temp.val);
            temp=temp.next;
        }
        while(st.empty()!=true || reverse!=null)
        {
            if(st.pop()!=reverse.val)
            {
                return false;
            }
            reverse=reverse.next;
        }
        return true;


    }
}