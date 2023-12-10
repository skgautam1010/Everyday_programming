// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int preindex;
    Node* building_tree(int in[],int pre[],int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        
        Node *root=new Node(pre[preindex++]);
        int inorder_index;
        
        for(int i=start;i<=end;i++)
        {
            if(in[i]==root->data)
            {
                inorder_index=i;
                break;
            }
        }
        root->left=building_tree(in,pre,start,inorder_index-1);
        root->right=building_tree(in,pre,inorder_index+1,end);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
       
        preindex=0;
        Node *root=building_tree(in,pre,0,n-1);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends