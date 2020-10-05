#include<iostream>
#define NIL -1
using namespace std;

int memo[100001];
int dp[100001];

void _inintialize(){
  long i;
  for(i=0;i<100001;i++)
    memo[i] = NIL;
}

int fibo_top_down(int n){
  if(memo[n]==NIL){
    if(n<=1){
      memo[n] = n;
    }
    else
      memo[n] = fibo_top_down(n-1) + fibo_top_down(n-2);
  }
  return memo[n];
}

void fibo_bottom_up(){
  dp[0]=0;
  dp[1]=1;
  long i;
  for(i=2;i<100001;i++)
    dp[i]=dp[i-1]+dp[i-2];
}

int main(){
  long long int n;
  cin>>n;
  _inintialize();
  fibo_bottom_up();
  cout<<fibo_top_down(n)<<endl<<dp[n]<<endl;
}
