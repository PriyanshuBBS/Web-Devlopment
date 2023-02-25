#include <iostream>
using namespace std;

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

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

node *reverse_k(node *&head, int k)
{
    node *previous_ptr = NULL;
    node *current_ptr = head;
    node *next_ptr;

    int count = 0;

    // reversing the 1st k nodes
    while (current_ptr != NULL && count < k)
    {
        next_ptr = current_ptr->next;
        current_ptr->next = previous_ptr;

        // Moving 3 pointers, 1 step ahead
        previous_ptr = current_ptr;
        current_ptr = next_ptr; // After this current and next are at same position

        count++;
    }

    // Apply Recursion
    if (current_ptr != NULL)
    {
        head->next = reverse_k(current_ptr, k); // linking the 2 reversed link list
    }

    return previous_ptr;
}

void display(node *head)
{
    node *temp = head;
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
    insert_tail(head, 4);
    insert_tail(head, 5);
    insert_tail(head, 6);
    display(head);

    int k = 2;
    node *newhead = reverse_k(head, k);
    display(newhead);
    return 0;
}
