#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Node
{

public:
    string name;
    int data;
    Node* ptr;
};



void printdata(Node* N){
    while(N != NULL){
        cout<<"The Value of Data for "<<N->name<<" is "<<N->data<<endl;
        N = N->ptr;
    }
}


int main()
{
    

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->ptr = second;
    head->name = "Head";

    second->data = 2;
    second->ptr = third;
    second->name = "Second";

    third->data = 3;
    third->ptr = NULL;
    third->name = "Third";

    printdata(head);

    
    return 0;
}
