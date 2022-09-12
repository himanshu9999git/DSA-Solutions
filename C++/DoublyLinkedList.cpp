#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *insertAtTail(Node *head, int new_data)
{
    Node *new_node = new Node();
    Node *last = head;
    
    new_node->data = new_data;
    new_node->next = NULL;

    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return head;
    }

    while (last->next)
        last = last->next;

    new_node->prev = last;
    last->next = new_node;

    return head;
}

void printList(Node *node)
{
    while (!((node) == NULL))
    {
        cout << node->data << endl;
        node = node->next;
    }
}

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;

        head = insertAtTail(head, data);
    }

    Node *new_node = head;
    printList(new_node);

    while (head->next)
    {
        head = head->next;
        cout << head->prev << endl;
    }
    return 0;
}