#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int r,c,v;
    struct node *next;
}node;
int main()
{
    node *ptr,*head=NULL,*last;
    int r,c;
    printf("Enter the dimensions of the matrix\n");
    scanf("%d%d",&r,&c);
    int a[r][c];
    for (int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("enter the element\n");
            scanf("%d",&a[i][j]);
        }
    }
    printf("The entered matrix is\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if (a[i][j]!=0)
            {
                ptr = (node*)malloc(sizeof(node));
                if(head==NULL)
                {
                    head = ptr;
                    last = ptr;
                    ptr->v=a[i][j];
                    ptr->r=i;
                    ptr->c=j;
                    ptr->next=NULL;
                }
                else
                {
                    ptr->v=a[i][j];
                    ptr->r=i;
                    ptr->c=j;
                    last->next=ptr;
                    last = ptr;
                    ptr->next=NULL;
                }
            }
        }
    }
    ptr = head;
    while(ptr)
    {
        printf("%d %d %d \t",ptr->r,ptr->c,ptr->v);
        ptr = ptr->next;
    }
}
