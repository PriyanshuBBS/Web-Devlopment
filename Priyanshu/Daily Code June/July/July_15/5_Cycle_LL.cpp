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

bool detect(node *&head)
{

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL) // What condition should be? If cycle is present then loop break it self by auto
    // So, condition needed if it is not cyclic, Fast is ahead
    {
        slow = slow->next;       // 1 Step movement
        fast = fast->next->next; // 2 Step movement

        if (fast == slow)
        {
            return true;
        }
    }
}

// Forms a cycle at given position "pos"

void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode;

    int count = 1; // Moves till it equates to position
    while (temp->next != NULL)
    {

        if (count == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = startnode; // Forming the cycle
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

void removeCycle(node *&head)
{
    node *fast = head, *slow = head, *hold = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            while (slow != hold)
            {
                hold = hold->next;
                slow = slow->next;
            }
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
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

    makecycle(head, 3);
    // display(head);
    cout << detect(head) << endl;

    removeCycle(head);
    cout << detect(head) << endl;
    display(head);
    return 0;
}