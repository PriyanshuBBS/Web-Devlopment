#include <iostream>
using namespace std;

// Creating a User Defined Node for LL

class node
{
public:
    int data;
    node *next;

    node(int var)
    {
        data = var;
        next = NULL;
    }
};

void insert_tail(node *&head, int val)
{

    node *n = new node(val); // A new node created having, 'val' at its data field, and NULL in next
    //(How getting NULL in next? Since "class node" put NULL in next)

    if (head == NULL) // If the Linked List is Empty
    {
        head = n;
        return;
    }

    // A iterator for Traversing LL
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // After the above loop, 'temp' is at end;
    // Add the new valur in node

    temp->next = n; // Main Algo
}

node *reverse_recursive(node *&head) // Returning the head of rev LL
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = reverse_recursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
}

void display(node *head) // head is not taken & as no modification done
{
    node *temp = head; // here head can be used to traverse as head not called by ref.
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    display(head);

    node *newhead = reverse_recursive(head);
    display(newhead);
    return 0;
}
