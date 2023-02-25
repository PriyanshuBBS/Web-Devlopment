// Return head of Merged linked list

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

node *mergelist(node *&head1, node *&head2)
{

    node *ptr1 = head1;
    node *ptr2 = head2;
    node *dummy_node = new node(-1);
    node *ptr3 = dummy_node;

    while (ptr1 != NULL && ptr2 != NULL) // Traversing over both LL
    {
        // Comparing data & putting in Dummy list
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1; // Inserting in Dummy list
            ptr1 = ptr1->next; // Moving ptr in L1 forward
        }

        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }

        ptr3 = ptr3->next;
    }

    // A code needed if, both lists or any one not reached end

    while (ptr1 != NULL)
    {
        ptr3->next = ptr1; // Inserting in Dummy list
        ptr1 = ptr1->next; // Moving ptr in L1 forward

        ptr3 = ptr3->next;
    }

    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;

        ptr3 = ptr3->next;
    }

    return dummy_node->next;
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
    node *head1 = NULL;
    node *head2 = NULL;

    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {2, 3, 6};

    for (int i = 0; i < 4; i++)
    {
        insert_tail(head1, arr1[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        insert_tail(head2, arr2[i]);
    }

    display(head1);
    display(head2);

    node *newhead = mergelist(head1, head2);
    display(newhead);
    return 0;
}