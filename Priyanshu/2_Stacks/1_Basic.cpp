// September 8 -> Stack creation using Array and basic Stack Operations

#include <iostream>
using namespace std;
#define n 100

class stack
{
    int *arr; // Defining arr for stack
    int top;

public:
    stack()
    {
        arr = new int[n]; // Allocating memory or **** arr = new int [100];
        top = -1;         // -1 refers to empty stack
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Empty Stack\n";
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Empty stack\n";
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    cout << st.empty() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    return 0;
}
