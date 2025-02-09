//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class GfG {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data);
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int n = str.length;
            Node head = new Node(Integer.parseInt(str[0]));
            Node tail = head;
            for (int i = 1; i < n; i++) {
                tail.next = new Node(Integer.parseInt(str[i]));
                tail = tail.next;
            }
            Solution obj = new Solution();
            head = obj.addOne(head);
            printList(head);
        
System.out.println("~");
}
    }
}
// } Driver Code Ends


/*
class Node{
    int data;
    Node next;

    Node(int x){
        data = x;
        next = null;
    }
}
*/

class Solution {


    //Recursive optimal more space less time
    public int helper(Node temp) {
        
        if(temp == null) {
            return 1;
        }
        
        int carry = helper(temp.next);
        temp.data += carry;
        if(temp.data < 10) return 0;
        temp.data = 0;
        return 1;
    }
    
    public Node addOneRecursive(Node head) {
        // code here.
        if(head == null) {
            return head;
        }
        
        Node temp = head;
        int carry = helper(temp);
        
        if(carry == 1) {
            Node newNode = new Node(1);
            newNode.next = head;
            head = newNode;
        }
        return head;   
    }


    //Optimal Approach
    //more time less space
    public Node reverseLinkedList(Node head) {
        
        Node temp = head;
        
        Node prev = null;
        Node current = temp;
        
        while(temp != null) {
            
            temp = temp.next;
            current.next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    
    public Node addOne(Node head) {
        // code here.
        if(head == null) {
            return head;
        }
        Node newNode = reverseLinkedList(head);
        Node temp = newNode;
        int carry = 1;
        Node prev = null;
        while(temp != null) {
            
            if(carry == 0) {
                break;
            }
            
            if((temp.data+carry) % 10 == 0) {
                carry = 1;
                temp.data = 0;
            }
            else {
                temp.data = temp.data + carry;
                carry = 0;
            }
            prev = temp;
            temp = temp.next;
        }
        
        if(carry == 1) {
            Node createNode =  new Node(1);
            prev.next = createNode; 
        }
        
        Node result = reverseLinkedList(newNode);
        return result;
    }
    
    
}
