#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Stacknode{
    public:
    int data;
    Stacknode* next;
};

Stacknode* push(Stacknode* top, int new_data){
    Stacknode* newnode = new Stacknode();
    newnode->data = new_data;
    newnode->next = top;
    top = newnode;
    return top;
}

Stacknode* pop(Stacknode* top){
    if(top==NULL)
    cout<<"Stack Underflow";

    else{
    Stacknode* p = top;
    top = top->next;
    delete p;
    return top;
    }
}

void printList(Stacknode *node){

    cout<<endl;
    
    while(!((node)==NULL)){
        cout<<node->data<<endl;
        node = node->next;
        }
}


int main()
{
    Stacknode* top = NULL;
    top = push(top,17);
    top = push(top,10);
    top = push(top,23);
    top = pop(top);
    top = push(top,12);
    top = pop(top);

    printList(top);
    return 0;
}