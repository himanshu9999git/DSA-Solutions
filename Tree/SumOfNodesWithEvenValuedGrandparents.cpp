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
    void getsum(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return;

        if (root->val % 2 == 0)
        {
            if (root->left)
            {
                if (root->left->right)
                    sum += root->left->right->val;

                if (root->left->left)
                    sum += root->left->left->val;
            }

            if (root->right)
            {
                if (root->right->right)
                    sum += root->right->right->val;
                

                if (root->right->left)
                    sum += root->right->left->val;
            }
        }

        getsum(root->left, sum);
        getsum(root->right, sum);
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        int sum = 0;
        getsum(root, sum);

        return sum;
    }
};