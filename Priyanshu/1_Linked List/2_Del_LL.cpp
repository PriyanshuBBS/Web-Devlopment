// ********* Deletion in LL   *************

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

// Insert at Tail

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

// ***** Deletion ******

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }

    // If only 1 element, then how one can acess its next
    if (head->next == NULL)
    {
        node *todelete = head;
        head = head->next;
        delete todelete;
    }

    node *temp = head;

    while (temp->next->data != val) // Till It reaches the nth  node
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next; // n-1 linked to n+1;

    delete todelete; // Removing nth node from list
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

    // deletion(head,1);    // Deleting any position
    deletion(head, 1); // Deleting at head
    display(head);

    return 0;
}