#include<bits/stdc++.h>
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

bool isSym(Node *left, Node *right)
{
    if (right == NULL || left == NULL)
        return right == left;

    if (right->data != left->data)
        return false;

    return (isSym(right->right, left->left) && isSym(right->left, left->right));
}

bool isSymmetric(struct Node *root)
{
    if (root == NULL)
        return true;

    return isSym(root->left, root->right);
}

int main()
{
    
    return 0;
}