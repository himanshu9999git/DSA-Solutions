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

bool tree(Node *r1, Node *r2)
{
    if (r1 == NULL || r2 == NULL)
        return r1 == r2;

    if (r1->data != r2->data)
        return false;

    if (!tree(r1->right, r2->right) || !tree(r1->left, r2->left))
        return false;

    return true;
}

bool isIdentical(Node *r1, Node *r2)
{
    return tree(r1, r2);
}

int main()
{

    return 0;
}