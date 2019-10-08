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
       int n,sum=0,res=0;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)
        cin>>a[i];
       for(int i=0;i<n;i++)
       {
           if(sum+a[i]>0)
            sum+=a[i];
           else
            sum=0;
           res=max(res,sum);
       }
    if(res==0)
      cout<<*(max_element(a,a+n))<<endl;
    else
      cout<<res<<endl;
   }
   return 0;
}
