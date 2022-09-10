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

Node *lastRight(Node *root)
{
    while ((root->right != NULL))
    {
        root = root->right;
    }
    return root;
}

Node *helper(Node *root)
{
    if (root->right == NULL)
        return root->left;

    if (root->left == NULL)
        return root->right;

    Node *node = root->left;
    Node *lastright = lastRight(node);
    lastright->right = root->right;

    return root->left;
}

Node *del(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return helper(root);

    Node *node = root;

    while (node != NULL)
    {
        if (node->data > key)
        {
            if (node->left != NULL && node->left->data == key)
            {
                node->left = helper(node->left);
                break;
            }

            else
                node = node->left;
        }

        else
        {
            if (node->right != NULL && node->right->data == key)
            {
                node->right = helper(node->right);
                break;
            }

            else
                node = node->right;
        }
    }
    return root;
}

int main()
{

    return 0;
}