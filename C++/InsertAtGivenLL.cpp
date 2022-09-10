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

void InsertAtGiven(Node *head, int new_data, int pos){

    

    Node* new_node = new Node();
    new_node->data = new_data;


    for (int m = 1; m < pos; m++)
    {
        head = head->next;
    }
    

    new_node->next = head->next;
    head->next = new_node;
}

void printList(Node *node){
    while(!((node)==NULL)){
        cout<<node->data<<endl;
        node = node->next;
        }
}

int main()
{
    int i,n,k,pos;
    cin>>n;

    Node * head = NULL;

    for ( i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        InsertAtTail(&head,data);
    }

    cin>>k;
    cin>>pos;
    InsertAtGiven(head,k,pos);
    
    printList(head);
    
    return 0;
}