#include <iostream>
using namespace std;

void subseqAS(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int code = ch; // getting the ASCII value of ch

    string ros = s.substr(1);

    subseqAS(ros, ans); // Nothing Pass
    subseqAS(ros, ans + ch);    // Pass Alphabet
    subseqAS(ros, ans + to_string(code));   //Pass ASCII
}

int main()
{
    subseqAS("AB","");
    cout<<endl;
    return 0;
}