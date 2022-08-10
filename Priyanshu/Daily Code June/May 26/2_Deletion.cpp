#include <iostream>
using namespace std;

void display(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i]<<" ";
    }
    cout << endl;
}

void insertion(int A[], int max_size, int size,int index){
   
    for (int i = index; i <= size-1; i++)
    {
        A[i] = A[i+1];
    }

    // A[size-1]=0;    

    for (int i = 0; i < size-1; i++)
    {
        cout << A[i]<<" ";
    }
    cout << endl;       
    
}

int main()
{
    int A[20] = {12, 32, 42, 43};
    display(A, 4);


    int index;

    cout<<"Enter the Index for deletion ";
    cin>>index;
    insertion(A,20,4,index);
    return 0;
}