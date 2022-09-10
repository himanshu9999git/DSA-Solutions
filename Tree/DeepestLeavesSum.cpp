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

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *node)
    {
        if (node == NULL)
            return -1;
        else
        {
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);

            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }

    void sumLeaves(TreeNode *root, int n, int h, int &sum)
    {
        if (root == NULL)
            return;
        if (n == h)
            sum += root->val;

        sumLeaves(root->left, n + 1, h, sum);
        sumLeaves(root->right, n + 1, h, sum);
    }

    int deepestLeavesSum(TreeNode *root)
    {
        int h = maxDepth(root);
        int sum = 0;

        sumLeaves(root, 0, h, sum);
        return sum;
    }
};