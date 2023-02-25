#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int postfix(string s)
{

    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // if subrtract a number(which is in char string )  by 0 you get that number else ASCII value
        }

        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;

            default:
                cout << "Invalid Operator present\n";
            }
        }
    }
    return st.top();
}

int main()
{
    cout<<postfix("46+2/5*7+")<<endl;
    return 0;
}