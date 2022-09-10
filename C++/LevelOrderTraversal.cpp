#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
};

void LevelOrder(Node *root)
{
    if(root == NULL)
        return;
    
    
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node* current = q.front();
            cout<<current->data<<" ";

            if(root->left != NULL)
            q.push(current->left);

            if(root->right != NULL)
            q.push(current->right);

            q.pop();
        }

        
    
}

int main()
{
    
    return 0;
}