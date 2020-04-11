class Solution
{
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * 
 */
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    int m = 0;
    int trav(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = trav(root->left);
        int r = trav(root->right);
        if (root->left != NULL)
            l++;
        if (root->right != NULL)
            r++;
        //cout<<root->val<<" "<<l<<" "<<r<<" "<<endl;
        m = max(m, r + l);
        return max(r, l);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int t = trav(root);
        return m;
    }
};