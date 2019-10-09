string check(int n,string a)
{
    stack<char> s;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='(' || a[i]=='{'|| a[i]=='[')
        {
         s.push(a[i]);
         continue;
        }
        if(s.empty())
         return("not balanced");
        if(a[i]==')' && s.top()!='(')
        {
            s.pop();
            return ("not balanced");
        }
        if(a[i]=='}' && s.top()!='{')
        {
            s.pop();
             return ("not balanced");
        }
        if(a[i]==']' && s.top()!='[')
        {
            s.pop();
            return ("not balanced");
        }
        s.pop();
    }
    if(s.empty())
    return ("balanced");
    else
    return ("not balanced");
}
int main()
{
  fastio;
   int t;
   cin>>t;
   while(t--)
   {
     string a;
     cin>>a;
     int n=a.length();
     cout<<check(n,a)<<endl;
   }
   return 0;
}
