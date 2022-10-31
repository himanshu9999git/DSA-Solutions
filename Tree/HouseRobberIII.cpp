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

unordered_map<Node *, unordered_map<bool, int>> mp;
int solve(Node *root, bool flag)
{
    if (!root)
        return 0;

    if (mp.find(root) != mp.end() && mp[root].find(flag) != mp[root].end())
        return mp[root][flag];

    int lt, rt, lf, rf;
    lt = solve(root->left, true);
    rt = solve(root->right, true);
    lf = solve(root->left, false);
    rf = solve(root->right, false);

    if (flag)
        return mp[root][flag] = max(root->data + lf + rf, lt + rt);

    else
        return mp[root][flag] = lt + rt;
}

int rob(Node *root)
{
    return solve(root, true);
}

int main()
{

    return 0;
}