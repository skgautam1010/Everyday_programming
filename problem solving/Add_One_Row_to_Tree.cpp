/*Add One Row to Tree

Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.

Example 1:

Input: 
A binary tree as following:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

Output: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode *node=new TreeNode(v);
            node->left=root;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        for(int i=1;i<d-1;i++)
        {
            int s=q.size();
            while(s--)
            {
                TreeNode *node=q.front();
                q.pop();
                if(node->left !=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
        }
        while(!q.empty())
        {
            TreeNode *curr=q.front();
            q.pop();
            TreeNode *node1=new TreeNode(v);
            TreeNode *node2=new TreeNode(v);
            
            node1->left=curr->left;
            node1->right=NULL;
            curr->left=node1;
            
            node2->right=curr->right;
            node2->left=NULL;
            curr->right=node2;
        }
        return root;
    }
};