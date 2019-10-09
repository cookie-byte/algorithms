stack<int> s1;
int _stack :: getMin()
{
   //Your code here
   if(s.empty())
   return -1;
   int y=s1.top();
   return y;
}
/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty())
    return -1;
   int y=s.top();
   s.pop();
   s1.pop();
   if(!s1.empty())
   minEle=s1.top();
   return y;
}
/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty())
   {
       s1.push(x);
       minEle=x;
   }
   else
   {
       if(minEle>x)
        minEle=x;
       s1.push(minEle);
       minEle=s1.top();
   }
   s.push(x);
}

