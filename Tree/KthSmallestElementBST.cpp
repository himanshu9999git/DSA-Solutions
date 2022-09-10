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

void ino(Node *root, int k, int &n, int &count)
{
    if (root != NULL)
    {
        ino(root->left, k, n, count);
        count++;
        if (count == k)
        {
            n = root->data;
            return;
        }
        ino(root->right, k, n, count);
    }
}
int kthSmallest(Node *root, int k)
{
    int count = 0;
    int n = 0;
    ino(root, k, n, count);
    return n;
}

int main()
{

    return 0;
}