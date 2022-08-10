// **** In a tile box of 2 x n

#include<iostream>
using namespace std;

int tile(int n){
    if(n==0){
        return 0;
    }

    if(n==1){
        return 1;
    }

    return tile(n-1) + tile(n-2);   // Fibonaaci Series
}
int main()
{
    cout<<tile(4)<<endl;
return 0;
}