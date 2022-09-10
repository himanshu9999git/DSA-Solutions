/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
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
    void locate(TreeNode *original, TreeNode *target, int x, int y, pair<int, int> &p)
    {
        if (original == NULL)
            return;

        if (original->val == target->val)
        {
            p = make_pair(x, y);
            return;
        }

        locate(original->left, target, x - 1, y + 1, p);
        locate(original->right, target, x + 1, y + 1, p);
    }

    void getNode(TreeNode *cloned, int x, int y, int target, TreeNode *&head)

    {
        if (cloned == NULL)
            return;
        if (x == 0 && y == 0 && cloned->val == target)
            head = cloned;

        getNode(cloned->left, x + 1, y - 1, target, head);
        getNode(cloned->right, x - 1, y - 1, target, head);
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        pair<int, int> p;
        locate(original, target, 0, 0, p);

        int x = p.first;
        int y = p.second;
        TreeNode *head = NULL;

        getNode(cloned, x, y, target->val, head);
        return head;
    }
};