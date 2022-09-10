#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* push(Node* head, int new_data){
    Node * new_node = new Node();
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    return head;
}

Node* pop(Node *head){

    Node * ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    
    cout<<ptr->data;
    delete ptr;
    return head; 

    
}



int main()
{
    Node* head = NULL;
    string s;
    cin>>s;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if((s[i]>='a' and s[i]<='z') and (s[i]>='A' and s[i]<='Z'))
        cout<<s[i];

        else if(s[i]=='*' or s[i]=='/')
        head = push(head, s[i]);

        else if(s[i]=='+' or s[i]=='-')
        {
            if(head->data == '*' or head->data == '/')
            {
                while (head != NULL)
                {
                    head = pop(head);
                }
                head = push(head, s[i]);
                
            }
        }
        
    }
    while (head != NULL)
    {
        head = pop(head);
    }
    
    
    return 0;
}