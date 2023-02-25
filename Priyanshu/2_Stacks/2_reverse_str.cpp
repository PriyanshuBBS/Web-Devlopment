#include <iostream>
#include <stack>
using namespace std;

void reverse_sentence(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string word = "";

        // Traversing and Adding single word
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    string str ="Rajdhani Express runs at 130 Km/h";
    reverse_sentence(str);
    return 0;
}