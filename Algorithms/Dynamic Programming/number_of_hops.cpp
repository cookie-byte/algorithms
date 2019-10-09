// A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios_base::sync_with_stdio(false)
int dp[51];
void fun()
{
    dp[1]=1,dp[2]=2,dp[3]=4;
    for(int i=4;i<=50;i++)
      dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
}
int main()
{
  fastio;
   int t;
   cin>>t;
   fun();
   while(t--)
   {
       int n;
       cin>>n;
         cout<<dp[n]<<endl;
   }
   return 0;
}
