int main()
{
  fastio;
   int t;
   cin>>t;
   while(t--)
   {
       long long int n,i,curr=0,maxar=0,t;
       cin>>n;
       long long int a[n];
       for(i=0;i<n;i++)
       cin>>a[i];
       i=0;
       stack<int> s;
       while(i<n)
       {
           if(s.empty() || a[s.top()]<=a[i])
               s.push(i++);
           else
           {
               t=s.top();
               s.pop();
               curr=a[t]*(s.empty()?(i):(i-s.top()-1));
               maxar=max(maxar,curr);
           }
       }
       while(!s.empty())
       {
              t=s.top();
               s.pop();
               curr=a[t]*(s.empty()?(i):(i-s.top()-1));
               maxar=max(maxar,curr);
       }
       cout<<maxar<<endl;
   }
   return 0;
}
