// When push is costly

#include <iostream>
#include <queue>
using namespace std;

class Stack
{
public:
    int N;
    queue<int> q1;
    queue<int> q2;

    Stack()
    {
        N = 0;
    }

    void push(int val)
    {
        q2.push(val); // @ 1
        N++;

        // @ 2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

       // @ 3 -> We replace so that further call can be done
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop()
    {
        if (q1.empty())
            return -1;

        int s = q1.front();
        q1.pop();
        return s;
    }

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return N;
    }
};

int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;

    cout<<st.pop()<<endl;
    cout << st.top() << endl;
    return 0;
}