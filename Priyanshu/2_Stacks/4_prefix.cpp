#include <iostream>
#include<math.h>
#include <stack>
using namespace std;

int prefix_eval(string s)
{
    stack<int> st;

    for (int i = s.length()-1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }

        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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
                st.push(op1 ^ op2);
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
    string st ="-+7*45+20";
    cout<<prefix_eval(st)<<endl;
    return 0;
}