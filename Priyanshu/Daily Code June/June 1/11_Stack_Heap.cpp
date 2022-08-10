#include <iostream>
using namespace std;
int main()
{
    int a = 10; // Stored in stack

    int *p = new int(); // Creating a Pointer , that lives in stack but points to some memory in Heap

    *p = 10;    // The Pointer points to a  value "10" that is in heap
    
    delete (p); // Delinking the value 10 to p

    // Now the pointer p became a Dangling Pointer -=> two things can be done 1) Repoint to a value 2) make NULL pointer

    *p = new int [4];   // Points to a array

    delete [] p;

    p = NULL;   // Making it a null pointer

    return 0;
}