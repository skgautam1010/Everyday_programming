class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp=head;
        int count=0;
        if(head==null)
        {
            return head;
        }
        while(temp!=null)
        {
            count++;
            temp=temp.next;
        }
        int node_remove=count-n;
        if(count==n)
        {
            return head.next;
        }
       
        temp=head;
        while(temp!=null)
        {
            node_remove--;
            if(node_remove==0)
            {
                break;
            }
            
            temp=temp.next;
            
        }
        if(n==1)
        {
            temp.next=null;
            return head;
        }
        temp.next=temp.next.next;

        return head;
    }
}