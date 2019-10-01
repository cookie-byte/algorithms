#include <stdio.h>
#define max 10
int pt[max];
int top=-1;
void push(int x)
{
    if(top>max)
    printf("stackoverflow");
    else
    {
        pt[++top]=x;
    }
}
int pop()
{
if(top==-1)
printf("stackunderflow");
else{
printf("the number popped is");
return pt[top--];
}
}
void display()
{
    int i;
    for( i=top;i>=0;i--)
    printf("%d\n",pt[i]);
}
void peek()
{
    printf("%d\n",pt[top]);
}
void size()
{
    printf("the size of stack is %d\n",top+1);
}
int main() {
    int temp;
  int op;
 do{
      printf("1)push\n2)pop\n3)display\n4)peek\n5)size\n");
      scanf("%d",&op); 
  switch(op)
  {
  case 1:
      printf("enter a number\n");
      scanf("%d",&temp);
      push(temp);
      break;
  case 2:
      printf(" %d\n",pop());        
      break;
  case 3:
      printf("the stack is\n");
      display();
      break;
  case 4:
      printf("the top number is\n");
      peek();
      break;
 case 5:
 size();
  }
}while(op>0&op<6);
    return 0;
}
