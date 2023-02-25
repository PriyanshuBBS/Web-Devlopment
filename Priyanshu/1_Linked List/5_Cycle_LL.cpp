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

    while (fast != NULL && fast->next != NULL) // What condition should be? If cycle is present then loop break it self by auto by virtue of ##51
    // So, Condition needed if it is not cyclic, Fast is ahead
    {
        slow = slow->next;       // 1 Step movement
        fast = fast->next->next; // 2 Step movement  Due to this, 2nd condition needed in while

        if (fast == slow)
        {
            return true; // If cycle is present, loop break at this position
        }
    }
    return false;
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

    temp->next = startnode; // Forming the cycle : Connecting the end of LL to the desired position
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

void removecycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    // Applying Flyod's Algorithm, to put both slow and fast at same point
    do
    {
        slow = slow->next;
        fast = fast->next->next;

    } while (slow != fast);

    // Point 2 -> put any one(slow/fast) at start
    slow = head;

    while (slow->next != fast->next) // Till start of cycle
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow = NULL;
}

void removeLoop(node *&head)
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

    // removeLoop(head);
    cout << detect(head) << endl;
    display(head);
    return 0;
}