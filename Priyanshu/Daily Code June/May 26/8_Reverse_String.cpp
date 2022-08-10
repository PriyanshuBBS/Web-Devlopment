#include <iostream>
#include <string.h>

using namespace std;

string reverse(string A)
{
    int n = A.length();
    string B;

    for (int i = 1; i <= n; i++)
    {
        B += A[n - i];
    }
    return B;
}
int main()

{
    string A = "Pakistan";

    cout << reverse(A) << endl;

    return 0;
}

// Stack Overflow Answer

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string A="India";
    string B;
    int n=A.length();
    B.resize(n);    //allocating the memory for B
   for (int i = n-1; i >= 0; i--) {
      B[n-i-1] = A[i];  
   }
   
   
       cout<<B[i];
   
return 0;
}