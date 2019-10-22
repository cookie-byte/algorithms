#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class stack
{
	     int stk[5];
	     int top;
      public:
	     stack()
	      {
		top=-1;
	       }
	     void push(int x)
	      {
		 if(top >  4)
		       {
			   cout<<"Stack OverFlow.";
			   return;
		       }
		 stk[++top]=x;
		 cout <<"Inserted element is: " <<x;
	       }
	     void pop()
	       {
		  if(top <0)
		   {
			 cout <<"Stack UnderFlow.";
			 return;
		    }
		    cout <<"Deleted element is: " <<stk[top--];
		}
	     void topp()
	     {
		 {
		  if(top <0)
		   {
			 cout <<"Stack UnderFlow.";
			 return;
		    }
		    cout <<"Element at the top is : " <<stk[top]<<endl;
		}
	     }
	     void display()
	       {
		   if(top<0)
		    {
			    cout <<"Stack is Empty.";
			    return;
		    }
		    for(int i=top;i>=0;i--)
			cout <<stk[i] <<" ";
		}
};
void main()
{
     clrscr();
     int ch;
     stack st;
     cout<<"*****Stack Implementation using array*****";
     while(1)
	{
	     cout<<"\n1.Push  2.Pop  3.Top  4.Display  5.Exit\nEnter your choice: "<<endl;
	     cin>>ch;
	     switch(ch)
	      {
	       case 1:  cout <<"\nEnter the element to be added: "<<endl;
			cin>>ch;
			st.push(ch);
			break;
	       case 2:  st.pop();
			break;
	       case 3:  st.topp();
			break;
	       case 4:  st.display();
			break;
	       case 5:  exit(0);
	       }
	 }
    getch();
}
