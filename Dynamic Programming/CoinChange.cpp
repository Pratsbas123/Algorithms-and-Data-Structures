// Coin Change
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define up upper_bound
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        int coin[n+2];
        for(int i=1;i<=n;i++)
            cin>>coin[i];
        int dp[n+2][s+2];
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(j>=coin[i])
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j]-coin[i]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<dp[n-1][s]<<endl;
    }
}
