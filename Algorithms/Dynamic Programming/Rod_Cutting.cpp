#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios_base::sync_with_stdio(false)
int main()
{
  fastio;
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int val[n],dp[n+1][n+1];
       for(int i=0;i<n;i++)
        cin>>val[i];
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=n;j++)
           {
               if(i==0 || j==0)
                dp[i][j]=0;
               else if(i<=j)
                dp[i][j]=max(val[i-1]+dp[i][j-i],dp[i-1][j]);
               else
                dp[i][j]=dp[i-1][j];
           }
       }
      cout<<dp[n][n]<<endl;
   }
   return 0;
}
