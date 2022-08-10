#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "sjkajdkjnakdsbkdca";

    int check[26]; // as 26 character

    // Initialize check with 0
    for (int i = 0; i < 26; i++)
    {
        check[i] = 0;
    }

    // Changing Check arr, for calcualtion
    for (int i = 0; i < s.length(); i++)
    {
        check[s[i] - 'a']++;
    }

    int res = 0;
    char c;
    // Traversing over check array to find, the alphabet
    for (int i = 0; i < 26; i++)
    {
        if (check[i] > res)
        {
            res = check[i];
            c = i+'a';
        }
    }

    cout<<res<<c<<endl;
    return 0;
}