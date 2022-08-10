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

node *reverse(node *&head) // Returning the head of rev LL
{
    node *previous_ptr = NULL;
    node *current_ptr = head;
    node *next_ptr;

    while (current_ptr != NULL)
    {
        next_ptr = current_ptr->next;
        current_ptr->next = previous_ptr;

        // Moving 3 pointers, 1 step ahead
        previous_ptr=current_ptr;
        current_ptr=next_ptr;
    }

    return previous_ptr;
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

   node* newhead = reverse(head);
   display(newhead);
    return 0;
}
