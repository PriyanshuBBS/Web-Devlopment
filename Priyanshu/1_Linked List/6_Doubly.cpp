// September 7

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *pre;
    node *next;

    node(int val)
    {
        data = val;
        pre = NULL;
        next = NULL;
    }
};

void insert_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->pre = n; // Can only be used if head's prev is not NULL
    }

    head = n;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insert_tail(node *&head, int val)
{
    // If head is NULL then pre can't be acessed
    if (head == NULL)
    {
        insert_head(head, val);
        return;
    }
    
    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->pre = temp;
}

void deletion(node *&head, int pos)
{ // If head deletion needed
    if (pos == 1)
    {
        node *todelete = head;
        head = head->next;
        head->pre = NULL;
        delete todelete;
        return;
    }
    node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos)
    {
        temp = temp->next;
        count++;
    }

    temp->pre->next = temp->next;

    if (temp->next != NULL) // Handling last node
        temp->next->pre = temp->pre;

    delete temp;
}
int main()
{
    node *head = NULL;
    insert_tail(head, 12);
    insert_tail(head, 24);
    insert_tail(head, 36);
    insert_tail(head, 48);
    insert_tail(head, 60);
    insert_tail(head, 72);

    display(head);
    deletion(head, 4);
    display(head);
    deletion(head, 1);
    display(head);
    return 0;
}