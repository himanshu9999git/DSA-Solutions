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

bool isLeaf(Node *node)
{
    if (node->right == NULL && node->left == NULL)
        return true;

    else
        return false;
}

void lst(Node *root, vector<int> &v)
{
    Node *node = root->left;
    while (node != NULL)
    {
        if (!isLeaf(node))
            v.push_back(node->data);

        if (node->left != NULL)
            node = node->left;

        else
            node = node->right;
    }
}

void rst(Node *root, vector<int> &v)
{
    vector<int> a;
    Node *node = root->right;
    while (node != NULL)
    {
        if (!isLeaf(node))
            a.push_back(node->data);

        if (node->right != NULL)
            node = node->right;

        else
            node = node->left;
    }

    for (int i = a.size() - 1; i >= 0; i--)
    {
        v.push_back(a[i]);
    }
}

void leaves(Node *node, vector<int> &v)
{
    if (node != NULL)
    {
        if (isLeaf(node))
            v.push_back(node->data);

        leaves(node->left, v);
        leaves(node->right, v);
    }
}

vector<int> boundary(Node *root)
{
    vector<int> v;

    if (root == NULL)
        return v;

    if (!isLeaf(root))
        v.push_back(root->data);

    lst(root, v);
    leaves(root, v);
    rst(root, v);

    return v;
}

int main()
{

    return 0;
}