// Longest Common Substring
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
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.length();
        int m=s2.length();
        int dp[n+1][m+1];
        for(int i=0;i<m;i++)
            dp[0][i]=0;
        int ma=INT_MIN;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s1[i]==s2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
                if(ma<dp[i][j])
                    ma=dp[i][j];
            }
        }
        cout<<ma<<endl;
    }
    return 0;
}
