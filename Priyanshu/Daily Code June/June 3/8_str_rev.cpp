#include<iostream>
using namespace std;

void revstr(string s1){
    if(s1.length()==0){
        return;
    }

    string tempstr = s1.substr(1);
    revstr(tempstr);
    cout<<s1[0];

}


int main()
{
    revstr("Rajdhani");
    cout<<endl;
return 0;
}