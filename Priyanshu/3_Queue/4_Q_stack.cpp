// Implementing 1 Stack

#include <iostream>
#include <stack>
using namespace std;

class que
{
    stack<int> st;

public:
    void enqueue(int x)
    {
        st.push(x);
    }

    // Removes and Print the element from queue
    int dequeue()
    {
      /* 1. Pop all the elements from Main Stack recursively until Stack size is equal to 1.
         2. If Stack size = 1, Pop item from Stack, and return the same item.
         3. Push all popped element back to Stack.*/
      
      
      
        // @ 1 If there is nothing in the stack, (& This is the base condition for recursion)
        if (st.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        // @ 2 If only one element present -> Base condition
        int x = st.top();
        st.pop();
        if (st.empty())
        {
            return x;
        }

        // @ 3
        int item = dequeue();  // Recursively pop everything from the stack, store the popped item in a variable
        st.push(x);
        return item;
    }

    void empty()
    {
        if (st.empty() && st.empty())
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