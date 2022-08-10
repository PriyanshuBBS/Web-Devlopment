#include <iostream>
using namespace std;

int friend_pair(int n)
{

    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }

    return friend_pair(n-1) + friend_pair(n-2)(n-1);
}
int main()
{
    cout<<friend_pair(4)<<endl;
    return 0;
}