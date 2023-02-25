// Implementing using 2 Stacks

#include <iostream>
#include <stack>
using namespace std;

class que
{
    stack<int> s1; // for enqueue
    stack<int> s2; // for dequeue

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    // Removes and Print the element from queue
    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        // If there is nothing in the Dequeue stack
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();   // This pop is of Stack 1
            }
        }

        int topval = s2.top();
        s2.pop();
        return topval;
    }

    void empty()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue is not empty\n";
        return;
    }
};

int main()
{
    que q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.empty();
    cout << q.dequeue() << " ";
    q.enqueue(5);

    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " \n";

    q.empty();
    return 0;
}