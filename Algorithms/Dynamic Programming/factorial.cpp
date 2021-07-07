#include<iostream>
using namespace std;
int main(){
  long long  int n,i;
  cin>>n;
  long long int p=1;
  for(i=1;i<=n;i++){
    p =p*i;
  }
  cout<<p<<endl;
}
