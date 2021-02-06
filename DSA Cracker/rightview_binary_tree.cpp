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
    void traverse(TreeNode *root,int pos,vector<int>& result)
    {
        if(root==NULL)
        {
            return;
        }
        if(result.size()==pos)
        {
            result.push_back(root->val);
        }
        traverse(root->right,pos+1,result);
        traverse(root->left,pos+1,result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        traverse(root,0,result);
        return result;
    }
};