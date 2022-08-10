#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "priyanshu dhal";

    std::string::iterator it1;

    std::string::reverse_iterator it2;

    // Printing string - using iterator

    for (it1 = s.begin(); it1 != s.end(); it1++)
    {
        cout << *it1;
    }
    cout << endl;

    //  Printing string - using iterator and rend & rebegin funciton
    for (it2 = s.rbegin(); it2 != s.rend(); it2++)
    {
        cout << *it2;
    }
    cout << endl;

    return 0;
}
