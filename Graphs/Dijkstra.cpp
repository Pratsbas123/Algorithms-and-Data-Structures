/*
    Dijkstra's Algorithm
    Shortest Path for Weighted Undirected Graph with Positive Weights
    Using Sets (Self Balancing BST algorithm)
    Time Complexity - O(E*log(V))
    Author - Pratik Basu
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int,int> > graph[100001];
vector<bool> visited(100001,false);

int main()
{
    int edges,n;
    cout<<"Enter no of Nodes: ";
    cin>>n;
    cout<<"Enter no of Edges: ";
    cin>>edges;
    cout<<"\nEnter Edges and Weights: ";
    cout<<"\n\n[Node 1] [Node 2] [Weight] \n";
    set<int> f;
    for(int i=1;i<=edges;i++)
    {
        int x,y,weight;
        cin>>x>>y>>weight;
        f.insert(x);
        f.insert(y);
        graph[x].pb(mp(y,weight));
        graph[y].pb(mp(x,weight));
    }
    // Dijkstra
    int source;
    cout<<"\nEnter Source Vertex: ";
    cin>>source;
    int distance[100001];
    memset(distance,INF,sizeof(distance));
    distance[source]=0;
    set<pair<int,int> > S;
    S.insert(mp(0,source));
    while(!S.empty())
    {
        pair<int,int> P=*(S.begin());
        S.erase(S.begin());
        int v=P.second;
        if(visited[v])
            continue;
        visited[v]=true;
        for(auto x:graph[v])
        {
            int d=x.first;
            int w=x.second;
            if(distance[d]>distance[v]+w)
            {
                distance[d]=distance[v]+w;
                S.insert(mp(distance[d],d));
            }
        }
    }
    // Printing the Distances
    cout<<"\nMinimum distances from source vertex\n"<<endl;
    if(f.find(0)!=f.end())
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"Vertex: "<<i-1;
            cout<<" Distance: "<<distance[i-1]<<endl;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"Vertex: "<<i;
            cout<<" Distance: "<<distance[i]<<endl;
        }
    }
    return 0;
}
