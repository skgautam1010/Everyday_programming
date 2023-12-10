// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{   
    
    
    public:
    
    Node *reverselist(Node *head)
    {
        Node *prev=NULL,*next=NULL;
        Node *curr=head;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    Node *compute(Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        Node *temp=reverselist(head);
        /*Node *p=temp;
        while(p!=NULL)
        {
            cout<<p->data<<"->";
            p=p->next;
        }
        cout<<endl;*/
        
        Node *first=temp,*second=temp->next;
        while(second!=NULL)
        {
            if(first->data>second->data)
            {
                first->next=second->next;
                second=second->next;
            }
            else
            {
                first=first->next;
                second=second->next;
            }
        }
        Node *temp1=reverselist(temp);
        return temp1;
    }

    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends