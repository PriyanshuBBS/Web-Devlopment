// Find the bit at a position of a number

#include <iostream>
using namespace std;


// What is 0/1 at a position in a binary number
bool getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

// Make 1 at a position
int setbit(int n, int pos)
{
    return (n | (1 << pos)); // The number is return in decimal
}

// Make 0 at a postn in binary number
int clearbit(int n, int pos)
{
    return (n & ~(1 << pos));
}

// Change the bit at a position
int updatebit(int n, int pos, int value)
{
    n = (n & (~(1 << pos))); // cleared the position where value is needed to be stored
    return (n | (value << pos));    // Value used as to change it according to 0 or 1
}
int main()
{
    int n, pos, value;
    cin >> n >> pos >> value;

    cout <<getbit(n,pos)<< endl;
    cout<<setbit(n,pos)<<endl;
    cout<<clearbit(n,pos)<<endl;
    // cout << updatebit(n, pos, value) << endl;
    return 0;
}