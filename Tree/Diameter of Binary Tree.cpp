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

int width(Node *root, int &dm)
{
    if (root == NULL)
        return 0;

    int l = width(root->left, dm);
    int r = width(root->right, dm);

    dm = max(dm, l + r);

    return max(l, r) + 1;

    return 0;
}

int diameter(Node *root)
{
    int dm = 0;
    width(root, dm);
    return dm + 1;
}

int main()
{

    return 0;
}