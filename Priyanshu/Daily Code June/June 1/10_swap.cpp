#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a = 10, b = 20;

    int *ptr1 = &a;
    int *ptr2 = &b;

    swap(ptr1, ptr2);

    cout << a << " " << b << endl;

    return 0;
}