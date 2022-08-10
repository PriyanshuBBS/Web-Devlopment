// Different functions in string

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s1(5, 'a');
    cout << s1 << endl;

    string s = "Indiaaa";
    string s2 = "India";
    cout << s + s2 << endl;

    string s3 = "Odisha";
    cout << s3 << endl;
    s3.clear();
    cout << s3 << "Nill" << endl;

    if (s.compare(s2) > 0)
    {
        cout << "s gretaer than s2\n";
    }
    else
    {
        cout << "Not equal\n"
             << endl;
    }

    s.erase(4, 2);
    cout << s << endl;

    cout << s.find("nd") << endl;

    s.insert(5, "n-IND");
    cout << s << endl;
    return 0;
}