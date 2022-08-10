#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    // Generate the greatest number from a Numeric String
    string s = "18928919";

    sort(s.begin(), s.end(), greater<int>());

    cout << s << endl;
    return 0;
}