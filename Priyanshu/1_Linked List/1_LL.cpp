// ********* Linked List 1 - a) Node Creation  b) Insertion at Tail & Head    c) Searching     d) Display LL    *************

#include <iostream>
using namespace std;

// Creating a User Defined Node for LL

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

// Insert at Head
void insert_head(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

// Insert at Tail

void insert_tail(node *&head, int val)
{

    node *n = new node(val); // A new node created having, 'val' as its data field, and NULL in next
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
    // Add the new value in node

    temp->next = n; // Main Algo
}

// Searching

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }

        temp = temp->next;
    }
    return false;
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

    insert_head(head, 0);
    display(head);

    cout << search(head, 5) << endl;
    cout << search(head, 1) << endl;

    return 0;
}