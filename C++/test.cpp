#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    
};

unsigned int getfullcount(struct Node* node)
{
    if(!node)
    return 0;

    queue<Node *> q;

    int count = 0;
    q.push(node);

    while(!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();

        if (temp->left && temp->right)
        count++;

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);

    }

    return count;
}

struct Node* newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int main(void)
{
    struct Node *root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);

    root->left->right = newNode(7);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);

    root->right->right = newNode(9);
    root->right->right->left = newNode(7);

cout<<getfullcount(root);
return 0;


}