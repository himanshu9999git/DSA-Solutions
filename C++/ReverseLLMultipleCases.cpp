#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void InsertAtTail(Node** headref, int new_data){
    Node * new_node = new Node();
    Node * last = *headref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*headref == NULL)
    {
        *headref = new_node;
        return;
    }

    while(last->next!=NULL){
        last=last->next;
    }
    
    last->next = new_node;
    return;
}

Node* ReverseList(Node*head){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
    }

void printList(Node *node){

    cout<<endl;
    
    while(!((node)==NULL)){
        cout<<node->data<<endl;
        node = node->next;
        }
}

int main()
{
    int i,j,n,t;
    
    cin>>t;
    Node * head[t] = {NULL};
    for ( j = 0; j < t; j++)
    {
        cin>>n;

    

    for ( i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        InsertAtTail(&head[j],data);
    }
    head[j] = ReverseList(head[j]);
    }
    
    for ( j = 0; j < t; j++)
    {
        printList(head[j]);
    }
    
    
    return 0;
}