#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class que
{
    node *front;
    node *back;

public:
    que()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {

        node *n = new node(x);

        if (front == NULL)
        {
            back = n;
            front = n;
        }
        else{
        // When queue is not null
        back->next = n;
        back = n;
        }
    }

    int pop()
    {
        if (front == NULL)
            return -1;
        else
        {
            node *toDelete = front;
            int popped = front->data;

            front = front->next;
            delete toDelete;

            return popped;
        }
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "No Element in Queue " << endl;
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << " ";
    q.pop();

    cout << q.peek() << " ";
    q.pop();

    cout << q.peek() << " ";
    q.pop();

    cout << q.peek() << " ";
    q.pop();

    cout << q.empty() << endl;
    return 0;
}