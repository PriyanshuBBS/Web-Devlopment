// *** Remove the duplicate from string

#include<iostream>
using namespace std;

string removeDup(string s){
    if(s.length()==0){
        return ""; //empty string return
    }

    char ch= s[0];
    string ans= removeDup(s.substr(1));

    if(ch == ans[0]){
        return ans;
    }
    return (ch+ans);
}

int main()
{

    cout<<removeDup("aaaaabbbbbbeeecccddd")<<endl;
    
return 0;
}