#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;
    
};

void Inorder(Node* root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}


int main()
{
    Node *root = new Node();
    root->data = 4;
    root->left->data = 2;
    root->right->data = 6;
    root->left->left->data = 1;
    root->left->right->data = 3;
    root->right->right->data = 7;
    root->right->left->data = 5;

    Inorder(root);
    return 0;
}