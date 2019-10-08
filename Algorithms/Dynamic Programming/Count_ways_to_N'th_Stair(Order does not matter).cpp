// There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).

#include<bits/stdc++.h>
using namespace std;
long long mod =1000000007;

long long countWays(int);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin>>m;
        cout<<countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
long long countWays(int m){
    // your code here
    int dp[m+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=m;i++)
    {
        if(i&1)
         dp[i]=dp[i-1];
        else
         dp[i]=dp[i-1]+1;
    }
    return dp[m];
}

