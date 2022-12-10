// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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

long long findSum(Node *root, vector<long long> &v)
{
    if (!root)
        return 0;

    long long a = root->data + findSum(root->left, v) + findSum(root->right, v);
    v.push_back(a);

    return a;
}
int maxProduct(Node *root)
{
    vector<long long> v;

    long long totalSum = findSum(root, v);
    long long finalans = 0;

    int n = v.size();
    int i = 0;
    while (i < n)
    {
        long long middle = v[i];
        long long ans = ((totalSum - middle) * (middle));

        finalans = max(ans, finalans);
        i++;
    }

    long long answer = finalans % 1000000007;
    return (int)answer;
}