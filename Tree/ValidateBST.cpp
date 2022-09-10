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

bool ino(Node *root, long long &m, long long &n)
{
    if (root != NULL)
    {
        if (!ino(root->left, m, n))
            return false;
        m = n;
        n = root->data;
        if (m >= n)
            return false;

        if (!ino(root->right, m, n))
            return false;
    }
    return true;
}

bool isValidBST(Node *root)
{
    long long m = 0;
    if (root != NULL)
    {
        long long n = LLONG_MIN;
        return ino(root, m, n);
    }
    else
        return false;
}

int main()
{

    return 0;
}
