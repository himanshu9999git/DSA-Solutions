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

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);

            v.push_back(temp->data);
        }
        ans.push_back(v);
    }
    return ans;
}

int main()
{

    return 0;
}