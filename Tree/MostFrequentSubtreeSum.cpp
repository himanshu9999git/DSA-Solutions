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

unordered_map<int, int> mp;
int solve(Node *root)
{
    if (!root)
        return 0;

    int sum = root->data + solve(root->left) + solve(root->right);
    mp[sum]++;

    return sum;
}

vector<int> findFrequentTreeSum(Node *root)
{
    solve(root);

    int mx = INT_MIN;
    for (auto i = mp.begin(); i != mp.end(); i++)
        mx = max(i->second, mx);

    vector<int> ans;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (mx == i->second)
            ans.push_back(i->first);
    }

    return ans;
}

int main()
{

    return 0;
}