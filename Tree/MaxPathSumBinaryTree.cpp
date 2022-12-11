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

int solve(Node *root, int &ans)
{
    if (!root)
        return 0;

    int left = max(0, solve(root->left, ans));
    int right = max(0, solve(root->right, ans));

    ans = max(ans, left + right + root->data);

    return max(left, right) + root->data;
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    solve(root, ans);

    return ans;
}

int main()
{

    return 0;
}