// 2D Vector


/*
    Create a vector containing "n"
    vectors each of size "m".

    vector<vector<int>> vec( n , vector<int> (m)); 

*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <vector<int>> v1{
        {1,2}, {2,3,4}, {2,34,5,2}
    };

    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[i].size(); j++)
        {
           cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }
    


return 0;
}