/*Construct Binary Tree from String with bracket representation
Difficulty Level : Medium
Last Updated : 12 Jul, 2021
Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root’s value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

Examples: 

Input : "1(2)(3)" 
Output : 1 2 3
Explanation :
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Preorder of above tree is "1 2 3".  

Input : "4(2(3)(1))(6(5))"
Output : 4 2 3 1 6 5
Explanation :
           4
         /   \
        2     6
       / \   / 
      3   1 5   
*/


#include<bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    Node *left,*right;
};

Node *newNode(int data)
{
    Node *node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int findindex(string str,int start,int end)
{
    if(start>end)
    {
        return -1;
    }
    stack<char>st;
    for(int i=start;i<=end;i++)
    {
        if(str[i]=='(')
        {
            st.push(str[i]);
        }
        else if(str[i]==')')
        {
            if(st.top()=='(')
            {
                st.pop();
                if(st.empty())
                {
                    return i;
                }
            }
        }
    }
    return -1;

}

Node* treefromstring(string str,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    Node *root=newNode(str[start]-'0');
    int index=-1;

    if(str[start+1]<=end && str[start+1]=='(')
    {
        index=findindex(str,start+1,end);
    }
    if(index!=-1)
    {
        root->left=treefromstring(str,start+2,index-1);

        root->right=treefromstring(str,index+2,end-1);
    }
    return root;

}


int main()
{
    string str="4(2(3)(1))(6(5))";
    //getline(cin,str);
    Node *root=treefromstring(str,0,(str.length()-1));
    preorder(root);

    return 0;
}