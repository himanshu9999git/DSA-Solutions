#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

ListNode *
insertAtHead(ListNode *head, int data)
{
    ListNode *nhead = new ListNode();
    nhead->val = data;

    nhead->next = head;
    head = nhead;

    return head;
}

int main()
{
    ListNode *head = new ListNode();
    head = NULL;

    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        head = insertAtHead(head, x);
    }

    cin >> k;

    ListNode *psuedo = head;
    int count = 0;
    while (psuedo != NULL)
    {
        psuedo = psuedo->next;
        count++;
    }

    int m = count - k;
    int i = 0;

    while (i < m)
    {
        head = head->next;
        i++;
    }

    cout << head->val;

    return 0;
}


//  2->1