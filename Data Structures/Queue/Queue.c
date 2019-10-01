#include<stdio.h>
#define max 10
int front=-1,rear=-1;
int que[max];
void enque(){
if(rear==max-1)
printf("Queue overflow\n");
else {
    if(front==-1)
    front=0;
    printf("Enter a number\n");
    int temp;
    scanf("%d",&temp);
    que[++rear]=temp;
}
}
void deque(){
if(front==-1 or front>rear)
printf("Queue underflow");
else{
    printf("Deleted number is %d\n",que[front++]);
}
}
void display()
{
if(front==-1&&rear==-1)
printf("Empty array");
else if(front>-1)
for(int i=front ;i<=rear;i++)
printf("%d\n",que[i]);
else
for(int i=0 ;i<=rear;i++)
printf("%d\n",que[i]);
}
void peek(){
printf("%d\n",que[front]);
}
void size(){
printf("%d\n",rear-front+1);
}
int main(){
int op;
 do{
      printf("1)enqueue\n2)dequeue\n3)display\n4)peek\n5)size\n");
      scanf("%d",&op); 
  switch(op)
  {
  case 1:
  enque();
      break;
  case 2:
      deque();
      break;
  case 3:
      printf("the stack is\n");
      display();
      break;
  case 4:
      peek();
      break;
 case 5:
 size();
  }
}while(op>0&op<6);
    return 0;
}
