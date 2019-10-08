#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios_base::sync_with_stdio(false)
int lcis(int a[],int b[],int n,int m)
{
    vector<int> v1(m,0);
    for(int i=0;i<n;i++)
       {
           int l=0;
           for(int j=0;j<m;j++)
           {
                 if(a[i]==b[j])
                  if(l+1>v1[j])
                    v1[j]=l+1;
                 if(a[i]>b[j])
                  if(v1[j]>l)
                   l=v1[j];
           }
       }
       int x= *max_element(v1.begin(),v1.end());
       return x;
}
int main()
{
  fastio;
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n;
       int a[n],i;
       for(i=0;i<n;i++)
        cin>>a[i];
        cin>>m;
        int b[m];
       for(i=0;i<m;i++)
        cin>>b[i];
        cout<<lcis(a,b,n,m)<<endl;
   }
}
