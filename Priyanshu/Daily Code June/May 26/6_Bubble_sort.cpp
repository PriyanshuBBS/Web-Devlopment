#include<iostream>
using namespace std;
int main()
{
    int a[5]={43,89,67,45,86};
    // Algorith for bubble sort by for [Made by me]
    // for (int j = 0; j < 5; j++)
    // {
    //     for (int i = 0; i < 5-j; i++)
    // {
    //     if(a[i]>a[i+1]){
    //         swap(a[i],a[i+1]);
    //     }
    // }
    // }

    //Algo for bubble sort by Apna collge by while loop
    int count=1;

    while(count<=5){
        
        for (int i = 0; i < 5-count; i++)
    {
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    count++;
    }
    

    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    
    cout<<endl;
    
return 0;
}



