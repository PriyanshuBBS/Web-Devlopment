#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int pre_char(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

string in_pre(string s)
{ // @1 Reversing string
    reverse(s.begin(), s.end());
    stack<char> st;
    string res;

    // @2 Replace ( with ) and vice versa
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }
    // @ 3 Apply Postfix operations
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        // Point 3
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            //    if (st.top() == '(')
            //     {
            //         st.pop();
            //     }
            st.pop();
        }
        else
        {

            // Loop will be excecuted if wrong precedence in stack
            while (!st.empty() && pre_char(st.top()) >= pre_char(s[i]))
            {
                res += st.top();
                st.pop();
            }
            // Pushing the current element of string into stack
            st.push(s[i]);
        }
    }

    //  After going through string, if anything remains in string
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    // @ 4 Reversing again
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << in_pre("A*B+C/D") << endl;
    return 0;
}