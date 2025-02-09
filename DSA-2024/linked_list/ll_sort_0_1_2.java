class Solution {
    // Function to sort a linked list of 0s, 1s and 2s.
    static Node segregate(Node head) {
        
        // TC: O(2N) Optimizing time and making it O(N)

          if(head==null || head.next==null)
        {
            return head;
        }
        // add your code here
       Node node_zero=new Node(-1);
       Node node_one=new Node(-1);
       Node node_two=new Node(-1);
       
       Node temp_zero=node_zero;
       Node temp_one=node_one;
       Node temp_two=node_two;
       Node temp=head;
       while(temp!=null)
       {
           if(temp.data==0)
           {
               temp_zero.next=temp;
               temp_zero=temp_zero.next;
           }
           else if(temp.data==1)
           {
               temp_one.next=temp;
               temp_one=temp_one.next;
           }
           else
           {
               temp_two.next=temp;
               temp_two=temp_two.next;
           }
           temp=temp.next;
       }
       temp_zero.next=(node_one.next!=null)?node_one.next:node_two.next;
       temp_one.next=node_two.next;
       temp_two.next=null;
       return node_zero.next;



        // SC: O(1) TC: O(2N)
        int count_0=0;
        int count_1=0;
        int count_2=0;
        
        Node temp=head;
        while(temp!=null)
        {
            if(temp.data==0)
            {
                count_0++;
            }
            if(temp.data==1)
            {
                count_1++;
            }
            if(temp.data==2)
            {
                count_2++;
            }
            temp=temp.next;
        }
        
        temp=head;
        while(temp!=null)
        {
            if(count_0>0)
            {
                temp.data=0;
                count_0--;
            }
            else if(count_1>0)
            {
                temp.data=1;
                count_1--;
            }
            else
            {
                temp.data=2;
                count_2--;
            }
            
            temp=temp.next;
            
        }
        
        return head;
    }
}
