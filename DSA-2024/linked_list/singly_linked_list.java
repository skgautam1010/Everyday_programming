import java.util.*;

class Node
{
    int data;
    Node next;


    Node(int data)
    {
        this.data=data;
        this.next=null;
    }

    Node(int data,Node next)
    {
        this.data=data;
        this.next=next;
    }

    public static Node create_singly_linked_list(int[] arr)
    {
        Node head=new Node(arr[0]);
        Node temp=head;
        
        for(int i=1;i<arr.length;i++)
        {
            Node new_node=new Node(arr[i]);
            temp.next=new_node;
            temp=new_node;
        }
        return head;
    }
    static void print_singly_linked_list(Node head)
    {
        Node temp=head;
        System.out.println("Values of singly liked list: ");
        while(temp!=null)
        {
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
        System.out.println("");
    }

    static Node reverse_singly_linked_list(Node head)
    {
        //Recursive Approach
        if(head==null || head.next==null)
        {
            return head;
        }
       Node newHead=reverse_singly_linked_list(head.next);
       Node front=head.next;
       front.next=head;
       head.next=null;
       return newHead;
        //Optimal Approach Iteration
       /* if(head==null || head.next==null)
        {
            return head;
        }
        Node temp=head;
        Node prev=null;
        Node current=temp;
        while(temp!=null)
        {
            temp=temp.next;
            current.next=prev;
            prev=current;
            current=temp;
        }

        return prev;*/

        //Brute Force Approach
        /*Stack<Integer>s=new Stack<>();
        Node temp=head;
        while(temp!=null)
        {
            s.push(temp.val);
            temp=temp.next;
        }
        temp=head;
        while(temp!=null)
        {
            temp.val=s.pop();
            temp=temp.next;
        }
        return head;*/
    }
    static Node middle_of_singly_linked_list(Node head)
    {
        //OPtimal Approach
        Node fast=head;
        Node slow=head;
        while(fast!=null && fast.next!=null)
        {
            fast=fast.next.next;
            slow=slow.next;
        }
        return slow;

        //Brute Force Approach
        /*int count=0;
        Node temp=head;
        if(head==null || head.next==null)
        {
            return head;
        }
        while(temp!=null)
        {
            count++;
            temp=temp.next;
        }
        temp=head;
        int counter=0;
        while(temp!=null)
        {
            counter++;
            if(counter==count/2)
            {
                if(count%2==0)
                {
                    return temp.next;
                }
                else
                {
                    return temp.next;
                }
                
            }
            temp=temp.next;
        }
        return temp;*/
        
    }

    static boolean cycle_in_linked_list(Node head)
    {

        //Optimal Approach
       if(head==null || head.next==null)
        {
            return false;
        }
        Node slow=head;
        Node fast=head;
        
        while(fast!=null && fast.next!=null)
        {
            fast=fast.next.next;
            slow=slow.next;
            if(fast==slow)
            {
                return true;
            }
            
            
        }
        return false;
        //Brute Force
       /* Node temp=head;
        HashMap<Node,Integer> visited=new HashMap<>();
        while(temp!=null)
        {
            
            if(visited.containsKey(temp))
            {
                return true;
            }
            visited.put(temp,1);
            temp=temp.next;
        }
        return false;*/
    }
    public static void main(String[] args)
    {
        int n;
        System.out.println("Enter the size of array: ");
        Scanner scanner=new Scanner(System.in);
        n=Integer.parseInt(scanner.nextLine());
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the "+i+" value inside array: ");
            arr[i]=Integer.parseInt(scanner.nextLine());
        }
        Node head=create_singly_linked_list(arr);
        System.out.println("The data of head is: "+head.data);
        print_singly_linked_list(head);
        Node middle_node=middle_of_singly_linked_list(head);
        System.out.println("The data of middle Node is: "+middle_node.data);
        Node new_head=reverse_singly_linked_list(head);
        System.out.println("head of reversed linked list: "+new_head.data);
        boolean cycle=cycle_in_linked_list(head);
        if(cycle)
        {
            System.out.println("There is a loop in Linked list");
        }
        else{
            System.out.println("No Loop Detected");
        }
    }
}

