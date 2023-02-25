// September 7 -> Tested in GFG

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

int len(node *head)
{
    int count = 0;

    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int intersect_check(node *&head1, node *&head2)
{

 int l1 = len(head1);
    int l2 = len(head2);
    int d = 0;
    node *ptr1, *ptr2;
    if (l1 > l2)
    {   d=l1-l2;
        ptr1 = head1;
        ptr2 = head2;
       
    }

    else
    {   
        d=l2-l1;
        ptr1 = head2;
        ptr2 = head1;
       
    }

   
    while (d)
    {
        ptr1 = ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {

        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

void interesect(node *&head1, node *&head2, int pos)
{
    node *ptr1 = head1;
    node *ptr2 = head2;

    while (pos - 1)
    {
        ptr1 = ptr1->next;
        pos--;
    }

    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
    }

    ptr2->next = ptr1;
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
    node *head1 = NULL;
    node *head2 = NULL;
    insert_tail(head1, 1);
    insert_tail(head2, 50);
    insert_tail(head1, 2);
    insert_tail(head2, 60);
    insert_tail(head1, 3);
    display(head1);
    display(head2);

    interesect(head1, head2, 2);
    cout << intersect_check(head1, head2)<<endl;

    return 0;
}