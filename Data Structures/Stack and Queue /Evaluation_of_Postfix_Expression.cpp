int main()
{
  fastio;
   int t;
   cin>>t;
   while(t--)
   {
       string a;
       cin>>a;
       stack<int> s;
       for(int i=0;i<a.length();i++)
       {
           if((a[i]-'0')>=0 && (a[i]-'0')<=9)
            s.push(a[i]-'0');
           else
           {
               int x=s.top();
               s.pop();
               int y=s.top();
               s.pop();
               switch(a[i])
               {
                   case '+':
                    s.push(y+x);
                    break;
                   case '-':
                    s.push(y-x);
                    break;
                   case '*':
                    s.push(y*x);
                    break;
                   case '/':
                    s.push(y/x);
                    break;
               }
           }
       }
       cout<<s.top()<<endl;
   }
   return 0;
}
