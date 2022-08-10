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

void insertion(int A[], int max_size, int size, int element, int index){
    if(size==max_size){
        cout<<"Memory Full\n";
    }

    else{
    for (int i = size; i >=index; i--)
    {
        A[i+1]=A[i];
    }

    A[index]=element;

    for (int i = 0; i < size+1; i++)
    {
        cout << A[i]<<" ";
    }
    cout << endl;       
    }
}

int main()
{
    int A[20] = {12, 32, 42, 43};
    display(A, 4);


    int element, index;

    cout<<"Enter the element and Index for insertion ";
    cin>>element>>index;
    insertion(A,20,4,element,index);
    return 0;
}