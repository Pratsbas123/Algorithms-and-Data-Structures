// Min Cost Path
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define up upper_bound
using namespace std;

int mini(int p,int q,int r)
{
    return min(min(p,q),r);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n+1][m+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<n;i++)
            a[i][0]=a[i-1][0]+a[i][0];
        for(int i=1;i<m;i++)
            a[0][i]=a[0][i-1]+a[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                a[i][j]=a[i][j]+mini(a[i-1][j-1],a[i][j-1],a[i-1][j]);
            }
        }
        int x,y;
        cin>>x>>y;
        cout<<a[x][y]<<endl;
    }
    return 0;
}
