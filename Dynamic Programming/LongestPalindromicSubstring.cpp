// Longest Palindromic Substring
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
        string s;
        cin>>s;
        int n=s.length();
        int dp[n+1][n+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
        }
        int flag=1,i1,j1;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i<j)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=dp[i+1][j-1]+2;
                        i1=i;
                        j1=j;
                        flag=0;
                        break;
                    }
                    else
                        dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
            }
            if(!flag)
                break;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i<j)
                {
                    if((s[i]==s[j]) && (abs(i1-i)==abs(j1-j)))
                    {
                        dp[i][j]=dp[i+1][j-1]+2;
                        i1=i;
                        j1=j;
                    }
                    else
                        dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<dp[0][n-1]<<endl;
    }
}
