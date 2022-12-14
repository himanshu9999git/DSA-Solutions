#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* InsertAtTail(Node* head, int new_data){
    Node * new_node = new Node();
    Node * last = head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    while(last->next!=NULL){
        last=last->next;
    }
    
    last->next = new_node;
    return head;
}

void printList(Node*head);

void Delete(Node *head, int pos){

    Node * ptr = head;

    if (pos == 0)
    {
        head = head->next;
        delete ptr;
        
        printList(head);
        return ;
    }
    
    else
    {
       for (int m = 1; m < pos; m++)
        {
            ptr = ptr->next;
        }
    
        Node * p = ptr->next;
        ptr->next = ptr->next->next;
        delete p; 
    }
    
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
    int i,n,pos;
    cin>>n;

    Node * head = NULL;

    for ( i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        head = InsertAtTail(head,data);
    }

    
    cin>>pos;
    Delete(head,pos);


    if(pos!=0)
    printList(head);
    
    return 0;
}