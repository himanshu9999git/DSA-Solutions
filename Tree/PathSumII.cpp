// https://leetcode.com/problems/path-sum-iii/

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

bool isLeaf(Node *root)
{
    if (!root->left && !root->right)
        return true;

    return false;
}

void solve(Node *root, int targetSum, vector<vector<int>> &ans, vector<int> v, int sum)
{
    if (!root)
        return;

    sum += root->data;
    v.push_back(root->data);

    if (isLeaf(root) && targetSum == sum)
        ans.push_back(v);

    solve(root->left, targetSum, ans, v, sum);
    solve(root->right, targetSum, ans, v, sum);
}

vector<vector<int>> pathSum(Node *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> v;
    solve(root, targetSum, ans, v, 0);
    return ans;
}

int main()
{

    return 0;
}