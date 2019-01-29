//Longest Increasing Subsequence
#include<bits/stdc++.h>
#define MAXN 10000
using namespace std;

int dp[MAXN];

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
    sort(dp,dp+n);
    cout<<dp[n-1];
    return 0;
}
