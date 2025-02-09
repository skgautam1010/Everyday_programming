class Solution {
    // Function to find the length of a loop in the linked list.



    
    public int countNodesinLoop(Node head) {
        // Add your code here.
        int counter=0;
        //Optimal Approach
        Node slow=head;
        Node fast=head;
        
        while(fast!=null && fast.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
            if(fast==slow)
            {
                slow=slow.next;
                counter++;
                while(fast!=slow)
                {
                    slow=slow.next;
                    counter++;
                }
                return counter;
            }
        }
        //Brute Force Approach

        /*HashMap<Node,Integer>visited=new HashMap<>();
        Node temp=head;
        while(temp!=null)
        {
            counter++;
            if(visited.containsKey(temp))
            {
                return (counter-visited.get(temp));
            }
            visited.put(temp,counter);
            temp=temp.next;
        }*/
        return 0;
    }
}