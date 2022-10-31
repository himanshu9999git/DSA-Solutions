// https://leetcode.com/problems/add-one-row-to-tree/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};

void solve(TreeNode *root, TreeNode *parent, int curdp, int depth, int val, bool isLeft)
{
    curdp++;
    if (curdp == depth)
    {
        TreeNode *newnode = new TreeNode(val);

        if (isLeft)
        {
            newnode->left = root;
            parent->left = newnode;
            return;
        }

        else if (!isLeft)
        {
            newnode->right = root;
            parent->right = newnode;
            return;
        }
    }
    if (!root)
        return;

    solve(root->left, root, curdp, depth, val, true);
    solve(root->right, root, curdp, depth, val, false);
}

TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *newroot = new TreeNode(val);
        newroot->left = root;
        return newroot;
    }

    solve(root->left, root, 1, depth, val, true);
    solve(root->right, root, 1, depth, val, false);

    return root;
}

int main()
{

    return 0;
}