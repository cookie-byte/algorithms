#include<iostream>

using namespace std;

int main(){
  long n,i;
  cin>>n;
  long long int dp[100001];
  dp[0]=1;
  for(i=1;i<100001;i++){
    dp[i] = dp[i-1]*i;
  }
  cout<<dp[n]<<endl;
}
