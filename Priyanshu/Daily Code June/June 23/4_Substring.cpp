// Print the sub string of a given string

#include <iostream>
using namespace std;

void subseq(string s, string ans = "")
{
    if (s.length() == 0)    // If string became 0/ Empty by default
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];

    string res = s.substr(1);

    subseq(res,ans);
    subseq(res,ans+ch);
}

int main()
{
    subseq("ABC","");
    cout<<endl;

    return 0;
}