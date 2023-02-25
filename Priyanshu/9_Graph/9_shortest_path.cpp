#include <bits/stdc++.h>
using namespace std;

// s and t nodes
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // adj list

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // Undirected Graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    parent[s] = -1;

    queue<int> q;
    q.push(s);
    visited[s] = true;

    // Parent Array
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // Prepare Shortest Path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while (currNode != s) // Backtracking from destination
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    return 0;
}