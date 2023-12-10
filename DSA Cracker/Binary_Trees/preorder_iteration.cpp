#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left,*right;

    Node(int x)
    {
        this->data=x;
        this->left=this->right=NULL;
    }
};

void preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }


    stack<Node*>st;
    st.push(root);

    while(!st.empty())
    {
        Node *root=st.top();
        st.pop();
        cout<<root->data<<" ";

        if(root->right)
        {
            st.push(root->right);
        }
        if(root->left)
        {
            st.push(root->left);
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    preorder(root);
}