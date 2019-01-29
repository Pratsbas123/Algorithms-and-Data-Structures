// Min Edit Dist
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define up upper_bound
using namespace std;

int mind(int p,int q,int r)
{
    return min(min(p,q),r);
}

int mine(string a,string b,int n,int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+mind(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n-1][m-1];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.length(),m=s2.length();
        cout<<mine(s1,s2,n,m)<<endl;;
    }
    return 0;
}
