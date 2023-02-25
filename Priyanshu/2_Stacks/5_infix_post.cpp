#include <iostream>
#include <stack>
using namespace std;


// Function to find the precedence of operators
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

string in_pos(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {   // Point 1
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }

        // Point 2
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        // Point 3
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
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

    // @4 After going through string, if anything remains in string 
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
int main()
{
    cout << in_pos("a+b*(c^d-e)^(f+g*h)-i") << endl;
    return 0;
}