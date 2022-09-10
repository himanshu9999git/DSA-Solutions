#include<bits/stdc++.h>
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
vector<int> zigZagTraversal(Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;
    vector<int> v;

    if (root == NULL)
        return v;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *curr = s1.top();
            v.push_back(curr->data);
            s1.pop();

            if (curr->left != NULL)
                s2.push(curr->left);

            if (curr->right != NULL)
                s2.push(curr->right);
        }

        while (!s2.empty())
        {
            Node *curr = s2.top();
            v.push_back(curr->data);
            s2.pop();

            if (curr->right != NULL)
                s1.push(curr->right);

            if (curr->left != NULL)
                s1.push(curr->left);
        }
    }
    return v;
}

int main()
{
    
    return 0;
}