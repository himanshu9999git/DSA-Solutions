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

Node *tree(vector<int> in, int instart, int inend, vector<int> pre, int prestart, int preend, map<int, int> mp)
{
    if (prestart > preend || instart > inend)
        return NULL;

    Node *root = new Node(pre[prestart]);

    int indroot = mp[root->data];
    int num = indroot - instart;

    root->left = tree(in, instart, indroot - 1, pre, prestart + 1, prestart + num, mp);
    root->right = tree(in, indroot + 1, inend, pre, prestart + num + 1, preend, mp);

    return root;
}

Node *buildTree(vector<int> in, vector<int> pre)
{
    int n = in.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }

    Node *root = tree(in, 0, n - 1, pre, 0, n - 1, mp);

    return root;
}

int main()
{

    return 0;
}