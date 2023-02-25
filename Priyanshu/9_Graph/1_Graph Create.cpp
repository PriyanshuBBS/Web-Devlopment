/*Coding Ninja Question Link : 
https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar*/

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class graph
{
public:
    // as list
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0) // If 2 way
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter the number of node"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph<int> g;

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        // direction = 0 : undirected
        // direction = 1 : directed
        g.addEdge(u,v,0);       // 0 can be changed to variable to allow both directed and undirected edges to form
    }
    
    g.printAdjList();
    return 0;
}