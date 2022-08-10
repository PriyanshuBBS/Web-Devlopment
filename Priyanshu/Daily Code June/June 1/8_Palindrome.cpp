#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char arr[n+1];

    cin>>arr;

    int flag = true;

    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=arr[n-1-i]){
            flag = false;
            break;
        }
    }

    if(flag==false){
        cout<<"Not Palindrome"<<endl;
    }
    else{
        cout<<"Palindrome\n";
    }
    
return 0;
}