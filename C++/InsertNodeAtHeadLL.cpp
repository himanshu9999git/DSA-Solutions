#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* InsertAtHead(Node* head, int new_data){
    Node * new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    return head;
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
    int i,n;
    cin>>n;

    Node * head = NULL;

    for ( i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        head = InsertAtHead(head,data);
    }
    
    printList(head);
    
    return 0;
}