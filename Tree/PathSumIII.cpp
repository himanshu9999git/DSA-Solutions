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

void solve(Node *root, int targetSum, int &ans, unordered_map<long long, long long> &mp, long long sum)
{
    if (!root)
        return;

    sum += root->data;

    if (mp.find(sum - targetSum) != mp.end())
        ans += mp[sum - targetSum];

    mp[sum]++;
    solve(root->left, targetSum, ans, mp, sum);
    solve(root->right, targetSum, ans, mp, sum);

    mp[sum]--;

    if (mp[sum] == 0)
        mp.erase(sum);

    sum -= root->data;
}

int pathSum(Node *root, int targetSum)
{
    unordered_map<long long, long long> mp;
    long long sum = 0;
    int ans = 0;

    mp[sum]++;
    solve(root, targetSum, ans, mp, sum);

    return ans;
}

int main()
{

    return 0;
}