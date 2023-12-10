


/*Reverse a Doubly Linked List
Easy Accuracy: 51.41% Submissions: 27559 Points: 2

Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3

Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75

Your Task:
Your task is to complete the given function reverseDLL(), which takes head reference as argument and should reverse the elements so that the tail becomes the new head and all pointers are correctly pointed. You need to return the new head of the reversed list. The printing and verification is done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 103
0 <= value of nodes <= 103

*/

// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};


/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}



 // } Driver Code Ends
//User function Template for C

struct Node* reverseDLL(struct Node * head)
{
    struct Node *curr=head;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    while(curr->next!=NULL)
    {
        struct Node *p=curr->next;
        curr->next=curr->prev;
        curr->prev=p;
        curr=curr->prev;
    }
    struct Node *q=curr->next;
    curr->next=curr->prev;
    curr->prev=q;
    return curr;
}

// { Driver Code Starts.

void displayList(struct Node* node)
{
    struct Node* last;
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
}

int main()
{   int t;
    scanf("%d", &t);
    while (t--){
  	  struct Node* head = NULL;
  	  int n;
  	  scanf("%d",&n);
	  for(int i = 0; i<n; i++){
	     int k;
	     scanf("%d",&k);
	     append(&head,k);}
	  head = reverseDLL(head);
	  displayList(head);
	  printf("\n");
    }
	return 0;
}
  // } Driver Code Ends