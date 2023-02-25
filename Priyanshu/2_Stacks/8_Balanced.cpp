#include <iostream>
#include <stack>
using namespace std;

bool balanced(string s)
{
    stack<char> st;
    bool ans = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (!st.empty() && s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (!st.empty() && s[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        // Added from GFG
        else{
            st.push(s[i]);
        }
    }

    if (!st.empty())
    {
        ans = false;
    }
    return ans;
}

int main()
{
    string s = "({[])}";

    cout << balanced(s) << endl;
    return 0;
}