#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *InsertAtTail(Node *head, int new_data)
{
    Node *new_node = new Node();
    Node *last = head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return head;
}

Node *ReverseList(Node *node)
{
    if (node == NULL)
        return NULL;
    if (node->next == NULL)
        return node;

    Node *node1 = ReverseList(node->next);
    
    node1->next = node;
    node->next = NULL;
    return node;
}

void printList(Node *node)
{

    cout << endl;

    while (!((node) == NULL))
    {
        cout << node->data << endl;
        node = node->next;
    }
}

int main()
{
    int i, n;
    cin >> n;

    Node *head = NULL;

    for (i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        head = InsertAtTail(head, data);
    }

    head = ReverseList(head);

    printList(head);

    return 0;
}