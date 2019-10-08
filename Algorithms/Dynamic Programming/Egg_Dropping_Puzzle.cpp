#include<bits/stdc++.h>
int main()
{
  fastio;
   int t;
   cin>>t;
   while(t--)
   {
     int n,e,i,j,curr=0;
     cin>>e>>n;
     int dp[e+1][n+1];
     for(i=1;i<=e;i++)
     {
         dp[i][1]=1;
         dp[i][0]=0;
     }
     for(j=1;j<=n;j++)
      dp[1][j]=j;
     for(i=2;i<=e;i++)
     {
         for(j=2;j<=n;j++)
         {
             dp[i][j]=INT_MAX;
             for(int k=1;k<=j;k++)
             {
                 curr=1+max(dp[i][j-k],dp[i-1][k-1]);
                 dp[i][j]=min(curr,dp[i][j]);
             }
         }
     }
     cout<<dp[e][n]<<endl;
   }
   return 0;
}
