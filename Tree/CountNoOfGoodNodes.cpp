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


void solve(Node *root, int &count, int mx)
{
    if (!root)
        return;

    if (root->data >= mx)
    {
        count++;
        solve(root->left, count, root->data);
        solve(root->right, count, root->data);
    }

    else
    {
        solve(root->left, count, mx);
        solve(root->right, count, mx);
    }
}

int goodNodes(Node *root)
{
    int count = 0;
    solve(root, count, INT_MIN);
    return count;
}

int main()
{

    return 0;
}