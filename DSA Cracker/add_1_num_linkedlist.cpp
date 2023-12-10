
/*Add 1 to a number represented as linked list
Easy Accuracy: 51.33% Submissions: 43316 Points: 2

A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 

Example 2:

Input:
LinkedList: 1->2->3
Output: 124 

Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node *pos=head;
        vector<int>val;
        while(pos!=NULL)
        {
            val.push_back(pos->data);
            pos=pos->next;
        }
        int carry=1;
        reverse(val.begin(),val.end());
        /*for(auto a:val)
        {
            cout<<a<<" ";
        }
        cout<<"\n";*/
        vector<int>sol;
        for(int i=0;i<val.size();i++)
        {
            val[i]=val[i]+carry;
            if(val[i]==10)
            {
                sol.push_back(val[i]%10);
            }
            else
            {
                sol.push_back(val[i]);
            }
            carry=val[i]/10;
        }
        if(carry!=0)
        {
            sol.push_back(carry);
        }
        reverse(sol.begin(),sol.end());
        
        /*for(auto x:sol)
        {
            cout<<x<<" ";
        }
        cout<<"\n";*/
        Node *temp=new Node(-1);
        Node *p=temp;
        int i=0;
        while(i<sol.size())
        {
            Node *newNode=new Node(sol[i++]);
            p->next=newNode;
            p=p->next;
        }
        return temp->next;
        
        
        
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends