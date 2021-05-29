
/*Intersection of two sorted Linked lists
Easy Accuracy: 29.44% Submissions: 42231 Points: 2

Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.

Example 2:

Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40

Your Task:
The task is to complete the function intersection() which should find the intersection of two linked list and add all the elements in intersection to the third linked list and return the head of the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n,m are the size of the linked lists.

Constraints:
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 1000
*/



// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node *newnode=new Node(-1);
    Node *p=newnode;
    
    set<int>s;
    set<int>s1;
    Node *temp1=head1,*temp2=head2;
    while(temp1!=NULL)
    {
        s.insert(temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        if(s.find(temp2->data)!=s.end())
        {
            s1.insert(temp2->data);
        }
        temp2=temp2->next;
    }
    set<int>::iterator it;
    for(it=s1.begin();it!=s1.end();it++)
    {
        Node *temp=new Node(*it);
            p->next=temp;
            p=p->next;
    }
    return newnode->next;
}