#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left,*right;

    Node(int x)
    {
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};

void inorder(Node *root)
{
    stack<Node *>st;

    Node *curr=root;

    while(!st.empty() || curr!=nullptr)
    {
        if(curr!=nullptr)
        {
            st.push(curr);
            curr=curr->left;
        }
        else{
            curr=st.top();
            st.pop();
            cout<<curr->data<<endl;
            curr=curr->right;
        }
    }
}


int main()
{
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    inorder(root);
    cout<<endl;
    return 0;
}