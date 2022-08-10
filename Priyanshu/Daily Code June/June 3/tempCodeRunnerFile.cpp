#include<iostream>
using namespace std;
bool sort(int arr[],int n){
if(n==1){   // A sureshot condition for sorted array
    return 1;
}

    return (arr[0]<arr[1] && sort(arr+1,n-1));


}
int main()
{
    
    int arr[]={1,2,23,4,5,6,7,8};

    int n = sizeof(arr)/sizeof(int);

    cout<<sort(arr,n)<<endl;

return 0;
}