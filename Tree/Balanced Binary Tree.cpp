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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int leftheight = height(root->left);
    if (leftheight == -1)
        return -1;

    int rightheight = height(root->right);
    if (rightheight == -1)
        return -1;

    if (abs(rightheight - leftheight) > 1)
        return -1;

    return max(leftheight, rightheight) + 1;

    return 0;
}
bool isBalanced(Node *root)
{
    return height(root) != -1;
}

int main()
{

    return 0;
}