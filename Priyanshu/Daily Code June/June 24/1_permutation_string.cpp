#include<iostream>
using namespace std;

void permutation(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    // How to get the string before and after if fix one char
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i]; // Storing the fix char

        string ros = s.substr(0,i)+s.substr(i+1); // The string except the fixed char
    
        permutation(ros,ans+ch);    // The end statement (movable char + fix char)
    }
    
}

int main()
{
    permutation("ABC","");
return 0;
}