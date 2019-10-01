#include<stdio.h>

#define max 10
int front = -1, rear = -1;
int que[max];
int is_full() {
  if (front == max - 1 && rear == 0 || front == rear - 1) {
    printf("Queue is full\n");
    return 1;
  } else
    return 0;

}
void right_enque() {
  if (is_full());
  else {
    if (front == -1) {
      front = 0;
      rear = 0;
    }
    if (front == max - 1)
      front = 0;
    printf("Enter a number\n");
    int temp;
    scanf("%d", & temp);
    que[front++] = temp;
  }
}
void left_enque() {
  if (is_full());
  else {
    if (front == -1) {
      front = 0;
      rear = 0;
    }
    if (rear == 0)
      rear = max - 1;
    printf("Enter a number\n");
    int temp;
    scanf("%d", & temp);
    que[rear--] = temp;
  }
}
int is_empty() {
  if (front == -1 || rear == -1) {
    printf("Empty Queue\n");
    return 1;
  } else
    return 0;
}

void right_deque() {
  if (is_empty());
  else {
    printf("Deleted number is %d %d\n", front, que[--front]);

    if (front == -1)
      front = max - 1;
  }
}
void left_deque() {
  if (is_empty());
  else {
    printf("Deleted number is %d %d\n", rear, que[++rear]);
    if (rear == max - 1)
      rear = 0;
  }
}
void display() {
  int i;
  if (is_empty());
  else if (rear <= front) {
    printf("Array is\n");
    for (i = rear + 1; i <= front; i++)
      printf("%d %d\n", i, que[i]);
  } else {
    printf("Array is\n");
    for (i = rear + 1; i < max; i++)
      printf("%d %d\n", i, que[i]);
    for (i = 0; i < front; i++)
      printf("%d %d\n", i, que[i]);

  }
}

int main() {
  int op;
  do {
    printf("1)right enqueue\n2)left enqueue\n3)right dequeue\n4)left dequeue\n5)display\n");
    scanf("%d", & op);
    switch (op) {
    case 1:
      right_enque();
      break;
    case 2:
      left_enque();
      break;
    case 3:
      right_deque();
      break;
    case 4:
      left_deque();
      break;
    case 5:
      display();
      break;
    }
  } while (op > 0 & op < 6);
  return 0;
}
