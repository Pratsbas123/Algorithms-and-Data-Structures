//Unweighted and Undirected Graph DFS
#include<bits/stdc++.h>
using namespace std;

int addEdge(vector<int> graph[],int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}

void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}

int printGraph(vector<int> graph[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<"Vertex "<<i<<":\n";
        for(auto j: graph[i])
        {
            cout<<"-> "<<j;
        }
        cout<<endl;
    }
}

int main()
{
    int v=5;
    vector<int> graph[v];
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    printGraph(graph,v);
    cout<<"\nDFS result: \n";
    DFS(graph,v);
    cout<<endl;
    return 0;
}
