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
void even_odd(node *&head)
{

    node *odd = head;
    node *even = head->next;
    node *even_start = even;

    while (odd->next != NULL && even->next != NULL)
    {

        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    // If odd is last number
    odd->next = even_start;

    // If even is last number 
    if (odd->next != NULL)
    {
        even->next = NULL;  // ?? Isn't it is pointing to the NULL by default
    }
}
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insert_tail(head, arr[i]);
    }

    display(head);

    even_odd(head);
    display(head);
    return 0;
}