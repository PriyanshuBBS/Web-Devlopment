#include<iostream>
using namespace std;
int main()
{
    int a[5]={43,89,67,45,86};

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if(a[j]<a[i]){
                swap(a[j],a[i]);
            } 
        }
        
    }

    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    
    cout<<endl;
    
return 0;
}





