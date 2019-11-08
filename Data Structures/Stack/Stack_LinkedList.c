#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *head,*ptr;

int top=-1;
void push(int x)
{
ptr=head;
struct node * newnode =(struct node *)malloc(sizeof(struct node *));
newnode->data=x;
newnode->next=ptr;
head=newnode;
top++;    

}
int pop()
{
if(top<0)
printf("stackunderflow");
else
{
printf("the number popped is: ");
ptr=head;
head=head->next;
int v= ptr->data;
free(ptr);
top--;
return v;
}

}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void peek()
{
    printf("%d\n",head->data);
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
