#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;

vector<int> graph[200005];
vector<bool> vis(200005,false);

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    vis[v]=true;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(auto i:graph[x])
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                q.push(i);
            }
        }
    }
}

int main()
{
    int e,v;
    cin>>e>>v;
    int n,m;
    for(int i=0;i<e;i++)
    {
        cin>>n>>m;
        graph[n].pb(m);
        graph[m].pb(n);
    }
    for(int i=0;i<v;i++)
    {
        if(vis[i]==false)
            bfs(i);
    }
    return 0;
}
