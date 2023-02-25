// Code Studio : Cycle in Directed Graph
#include <bits/stdc++.h>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        // Since the code in prev has Node starting from 0
        // Here it is from 1 so we change it to 0 so same code can be implemented
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    // Finding Indegrees
    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // Pushing value with 0 indegree
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // inc count
        cnt++;

        // neighbour indegree update
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    // A valid topological sort has same no. of nodes as in graph
    if (cnt == n)
    {
        return false;
    }
    else
        return true;
}

int main()
{
    return 0;
}