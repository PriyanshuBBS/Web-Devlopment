// Implement by Pop Costly
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
        q1.push(val);
        N++;
    }

    int pop()
    {
        if (q1.empty())
            return -1;

        // @ 1
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // @ 2
        int ans = q1.front();
        q1.pop();
        N--;

        // @ 3 -> We replace so that further call can be done
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }

    int top()
    {
        if (q1.empty())
            return -1;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
   
        int ans = q1.front();
        q2.push(ans);   // Because at next time top called stack would be removed
        
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }

    int size()
    {
        return N;
    }
};

int main()
{

    return 0;
}