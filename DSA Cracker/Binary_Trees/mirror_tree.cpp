#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node* createNode(int val)
{
    Node *newNode=new Node;
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
    
}
/*
Node* mirror(Node *root)
{
    if(root==NULL)
    {
        return root;
    }
    Node *t=root->left;
    root->left=root->right;
    root->right=t;
    if(root->left!=NULL)
    {
        mirror(root->left);
    }
    if(root->right!=NULL)
    {
        mirror(root->right);
    }
    return root;
}*/

void mirror(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    mirror(root->right);
    cout<<root->data<<"-->";
    mirror(root->left);
}
void inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"-->";
    inorder(root->right);
}

int main() {

    Node *root=createNode(2);
    root->left=createNode(1);
    root->right=createNode(8);
    root->left->left=createNode(12);
    root->right->right=createNode(9);
    inorder(root);
    cout<<endl;
    mirror(root);
	return 0;
}