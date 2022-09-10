#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int maxsum(Node *root, int &mx)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data;

    int l = maxsum(root->left, mx);
    int r = maxsum(root->right, mx);

    if (root->left != NULL && root->right != NULL)
    {
        mx = max(mx, l + r + root->data);
        return root->data + max(l, r);
    }
    
    if (root->left == NULL)
        return r + root->data;

    if (root->right == NULL)
        return l + root->data;
}

int maxPathSum(Node *root)
{
    int mx = INT_MIN;

    int ans = maxsum(root, mx);
    if (mx == INT_MIN)
        return ans;

    return mx;
}

int main()
{

    return 0;
}