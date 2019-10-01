#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
int main()
{
    int c=1,d;
    node *ptr,*head=NULL,*last;
    printf("Welcome to linked list implementation\n");
    printf(" Let's create a new linked list\n");
    while (c==1)
    {
        printf("enter the element\n");
        scanf("%d",&d);
        ptr = (node*)malloc(sizeof(node));
        ptr->data=d;
        if(head==NULL)
        {
            ptr->next=NULL;
            head=ptr;
            last=ptr;
        }
        else
        {
            ptr->next=NULL;
            last->next=ptr;
            last=ptr;

        }
        printf("Press 1 to enter next element,else 0\n");
        scanf("%d",&c);
    }
    printf(" Let's print the linked list\n");
    ptr = head;
    while(ptr)
    {
        printf("%d ",ptr->data );
        ptr=ptr->next;
    }
    return 0;
    
}
