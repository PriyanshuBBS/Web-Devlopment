#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next; // Since next ptr points to a Node hence it has class's type

    node(int var)
    {
        data = var;
        next = NULL;
    }
};

void insert_Head(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
    return;
}

// Making a Linked List in a circular form
void insert_tail_cir(node *&head, int val)
{
    node *n = new node(val);
    node *temp = head;
    // If empty Linked List
    if (head == NULL)
    {
        insert_Head(head, val);
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void display(node *head)
{

    node *temp = head;

    // do loop is used so that, last node can be printed
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp->next != head);
    cout << "NULL\n";
}

void delete_head(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *to_delete = head;
    temp->next = head->next;
    head = head->next;
    delete to_delete;
}

void deletion(node *&head, int pos)
{
    node *temp = head;
    int count = 0;

    if (pos == 1)
    {
        delete_head(head);
        return;
    }
    while (count != pos)
    {
        temp = temp->next;
        count++;
    }

    node *to_delete = temp->next;
    temp->next = temp->next->next; // Skips the todelete element's link
}

int main()
{
    node *head = NULL;
    insert_tail_cir(head, 1);
    insert_tail_cir(head, 2);
    insert_tail_cir(head, 3);
    insert_tail_cir(head, 4);
    display(head);
    insert_Head(head, 5);
    display(head);
    deletion(head, 1);
    display(head);
    return 0;
}