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

Node *PairWiseSwap(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = head;
    Node *curr = head->next;

    head = curr;

    while (true)
    {
        Node *next = curr->next;
        curr->next = prev;

        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            return head;
        }

        prev->next = next->next;

        prev = next;
        curr = prev->next;
    }
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
        head = InsertAtTail(head,data);
    }

    head = PairWiseSwap(head);
    
    printList(head);
    
    return 0;
}