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

static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        if (a[1] == b[1])
            return a[2] < b[2];

        else
            return a[1] < b[1];
    }

    return a[0] < b[0];
}

void solve(Node *root, vector<vector<int>> &v, int x, int y)
{
    if (root == NULL)
        return;

    v.push_back({x, y, root->data});

    solve(root->left, v, x - 1, y + 1);
    solve(root->right, v, x + 1, y + 1);
}

vector<vector<int>> verticalTraversal(Node *root)
{
    vector<vector<int>> v;
    solve(root, v, 0, 0);
    sort(v.begin(), v.end(), comp);

    vector<vector<int>> ans;
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> a;
        int x = v[i][0];
        while (i < v.size() && v[i][0] == x)
        {
            a.push_back(v[i][2]);
            i++;
        }
        i--;
        ans.push_back(a);
    }
    return ans;
}

int main()
{

    return 0;
}