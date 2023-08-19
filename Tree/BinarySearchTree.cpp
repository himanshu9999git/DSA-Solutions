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

void inorder(vector<int> &ans, Node *head)
{
    if (!head)
        return;

    inorder(ans, head->left);
    ans.push_back(head->data);
    inorder(ans, head->left);
}

void bst(int num, Node *head)
{
    if (num > head->data)
    {
        if (!head->right)
        {
            Node *decoy = new Node(num);
            head->right = decoy;
            return;
        }
        bst(num, head->right);
    }

    else
    {
        if (!head->left)
        {
            Node *decoy = new Node(num);
            head->left = decoy;
            return;
        }
        bst(num, head->left);
    }
}

vector<int> binarySearchTree(vector<int> &nums)
{
    vector<int> ans;
    if (!nums.size())
        return ans;

    Node *head = new Node(nums[0]);
    for (int i = 0; i < nums.size(); i++)
    {
        bst(nums[i], head);
    }
    inorder(ans, head);
    return ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = binarySearchTree(nums);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}