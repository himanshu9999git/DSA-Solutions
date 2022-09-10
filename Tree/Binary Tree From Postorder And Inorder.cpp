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

Node *tree(vector<int> in, int instart, int inend, vector<int> post, int poststart, int postend, map<int, int> mp)
{
    if (poststart > postend || instart > inend)
        return NULL;

    Node *root = new Node(post[postend]);

    int indroot = mp[root->data];
    int num = indroot - instart;

    root->left = tree(in, instart, indroot - 1, post, poststart, poststart + num - 1, mp);
    root->right = tree(in, indroot + 1, inend, post, poststart + num, postend - 1, mp);

    return root;
}

Node *buildTree(vector<int> in, vector<int> post)
{
    int n = in.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }

    Node *root = tree(in, 0, n - 1, post, 0, n - 1, mp);

    return root;
}

int main()
{

    return 0;
}