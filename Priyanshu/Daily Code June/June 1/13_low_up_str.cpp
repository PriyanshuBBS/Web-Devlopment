#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1 = "sjkdjsk";

    // Normal operation

    // Converting to UPPER
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] >= 'a' && s1[i] <= 'z')
        {
            s1[i] -= 32;
        }
    }

    cout << s1 << endl;

    // Reverting to lower
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1[i] += 32;
        }
    }

    cout << s1 << endl;

    // transform operation

    cout<<"transform () \n";

    //transform(<start_point of String>, <end pt. of Str>, <from where to operate>, <operation>);
    
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    cout << s1 << endl;

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    cout << s1 << endl;
    return 0;
}