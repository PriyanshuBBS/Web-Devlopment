#include <iostream>
#include <string>
using namespace std;
int main()
{
    // char s[10];
    string name;
    
    // ---> getline function ()

    // cin.getline(s, 10); // 10 Specify till where to read & s from where

    getline(cin,name);

    cout<<name<<endl;
    // cout<<s<<endl;
    
    // ---> Push back
    name.push_back('x');

    cout<<name<<endl;
    name.pop_back();


    //---> str manipulation

    // * String capacity : the size alloted to string
    cout<<name.capacity()<<endl;
    
    name.resize(5);

    cout<<name<<endl;


    return 0;
}