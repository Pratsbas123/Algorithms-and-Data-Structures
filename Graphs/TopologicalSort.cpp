#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> g[200005];
vector<bool> visited(200005,false);
vector<int> ts;

int top(int v)
{
    visited[v]=true;
    for(auto x:g[v])
    {
        if(visited[x]==false)
        {
            top(x);
        }
    }
    ts.pb(v);
}

int main()
{
    int e,v;
    cin>>e>>v;
    int n,m;
    for(int i=0;i<e;i++)
    {
        cin>>n>>m;
        g[n].pb(m);
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            top(i);
    }
    for(int i=ts.size()-1;i>=0;i--)
    {
        cout<<ts[i]<<" ";
    }
}
