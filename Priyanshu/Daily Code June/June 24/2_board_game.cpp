#include <iostream>
using namespace std;

int boardway(int s, int e) // starting & ending point
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
    {
        return 0;
    }

    int sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        sum += boardway(s + i, e);
    }

    return sum;
}

int main()
{
    cout << boardway(0, 3) << endl;
    return 0;
}