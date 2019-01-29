//Longest Bitonic Subsequence
#include<bits/stdc++.h>
#define MAXN 10000
using namespace std;

int dp1[MAXN],dp2[MAXN];

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        dp1[i]=1;
    for(int i=0;i<n;i++)
        dp2[i]=1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
                dp1[i]=max(dp1[i],dp1[j]+1);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[j]<a[i])
                dp1[i]=max(dp1[i],dp1[j]+1);
        }
    }
    int dp[MAXN];
    for(int i=0;i<n;i++)
    {
        dp[i]=dp1[i]+dp2[i]-1;
    }
    sort(dp,dp+n);
    cout<<dp[n-1];
    return 0;
}

