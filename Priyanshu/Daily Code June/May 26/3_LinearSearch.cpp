#include<iostream>
using namespace std;

int linear(int A[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(A[i]==element){
            return i;
        }
    }
    return -1;
    
}

int main()
{
    int A[]={12,378,67,378,57,928};
    int n = sizeof(A)/sizeof(int);

    cout<<"Enter the element to find";
    int element;
    cin>>element;

    cout<<"The Element "<<element<<" found at "<<linear(A,n,element)<<endl;
    return 0;
}