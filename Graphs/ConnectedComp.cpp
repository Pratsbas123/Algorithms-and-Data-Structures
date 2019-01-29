#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> graph[200005];
vector<bool> visited(200005,false);

int dfs(int v)
{
    visited[v]=true;
    cout<<v<<" ";
    for(auto x:graph[v])
    {
        if(visited[x]==false)
        {
            dfs(x);
        }
    }
}

int main()
{
    int e,v,n,m;
    cin>>e>>v;
    for(int i=0;i<e;i++)
    {
        cin>>n>>m;
        graph[n].pb(m);
        graph[m].pb(n);
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            dfs(i);
            cout<<endl;
        }
    }
}
