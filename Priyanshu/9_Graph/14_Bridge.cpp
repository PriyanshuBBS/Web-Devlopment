#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;


void dfs (int node, int parent, int &timer,vector<int> &disc,vector<int> &low,vector<vector<int>> &result,unordered_map<int, list<int>> &adj,
unordered_map<int, bool> &vis)
{
    vis[node] = true;
    disc[node] = low [node] = timer ++; //as dfs called timer needed to be increased

    for(auto nbr: adj[node])
    {
        // if comming back on same path, why to do somthing just ignore
        if(nbr == parent)
            continue;
        
        if(!vis[nbr])
        {
            dfs(nbr,node,timer,disc,low,result,adj,vis);

            //Since in case of back edge, the low of child got update as it could form a back edge
            low[node] = min(low[node],low[nbr]);

            //check edge is bridge
            // it would be a single way to reach the nbr (only then the condition would be true) through the node
            // as if it is not low would be updated (decreased) by some path
            if(low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }

        else
        {
            //node already visited and not parent
            //Back Edge condition
            low[node] = min(low[node],disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v); // at which time, node is reached
    vector<int> low(v);  // earliest possible time to reach
    int parent = -1;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;
    
    //dfs
    for (int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }

    return result;
    
}