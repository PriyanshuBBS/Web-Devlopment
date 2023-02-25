#include <iostream>
#include <stack>
using namespace std;
void insert_bottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele); //  At the end of recursion call, here largest element is put at bottom of stack
        return;
    }
    int tele = st.top();
    st.pop();
    insert_bottom(st, ele);

    st.push(tele); // Inserting back the element
}

void reverse_stack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverse_stack(st);
    insert_bottom(st, ele);
}

void display(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    display(st);
    cout << endl;
    reverse_stack(st);
    display(st);
    cout << endl;

    return 0;
}