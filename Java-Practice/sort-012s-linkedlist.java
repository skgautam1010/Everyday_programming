class ListNode {
    int data;
    ListNode next;

    ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

class Solution {
    public static void printList(ListNode head) {
        ListNode temp = head;
        while(temp!= null) {
            System.out.println(temp.data + " ");
            temp = temp.next;
        }
    }
    public static ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        ListNode temp = head;
        while(temp != null) {
            if(temp.data == 0) zeroCount++;
            else if(temp.data == 1) oneCount++;
            else twoCount++;
            temp = temp.next;
        }
        temp = head;
        while(zeroCount > 0) {
            temp.data = 0;
            temp = temp.next;
            zeroCount--;
        }
        while(oneCount > 0) {
            temp.data = 1;
            temp = temp.next;
            oneCount--;
        }
        while(twoCount > 0) {
            temp.data = 2;
            temp = temp.next;
            twoCount--;
        }
        return head;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        int[] arr = new int[]{2, 0, 1, 2, 0, 1, 0};
        ListNode temp = head;
        for(int i=0;i<arr.length;i++) {
            temp.next = new ListNode(arr[i]);
            temp = temp.next;
        }
        System.out.println("Original Linked List:");
        printList(head);

        head = sortList(head);

        System.out.println("Sorted Linked List:");
        printList(head);
    }
}