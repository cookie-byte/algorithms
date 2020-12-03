#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int c,e;
    struct node *next;
}node;

node* create()
{
    int choice=1,c,e;
    node *ptr,*head=NULL,*last;
    printf(" Let's create a polynomial\n");
    while (choice==1)
    {
        printf("enter the coefficient and exponent\n");
        scanf("%d %d",&c,&e);
        ptr = (node*)malloc(sizeof(node));
        ptr->c=c;
        ptr->e=e;
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
        scanf("%d",&choice);
    }
    printf(" Let's print the polynomial\n");
    ptr = head;
    while(ptr)
    {
        if(ptr->next==NULL)
        {
            printf("%d.x^%d\n",ptr->c,ptr->e );
            break; 
        }
        printf("%d.x^%d + ",ptr->c,ptr->e );
        ptr=ptr->next;
    }
    return head;
}

node*  polyadd(node* head1,node* head2)
{
    node *ptr1,*ptr2,*ptr3,*head3=NULL,*last3;
    ptr1 = head1;
    ptr2 = head2;
    while(ptr1 && ptr2)
    {
        ptr3 = (node*)malloc(sizeof(node));
        if(head3==NULL)
        {
            ptr3->next=NULL;
            head3=ptr3;
            last3=ptr3;
        }
        else
        {
            ptr3->next=NULL;
            last3->next=ptr3;
            last3=ptr3;
        }
        if(ptr1->e<ptr2->e)
        {
            ptr3->e = ptr1->e;
            ptr3->c = ptr1->c;
            ptr1 = ptr1->next;
        }
        else if(ptr1->e>ptr2->e)
        {
            ptr3->e = ptr2->e;
            ptr3->c = ptr2->c;
            ptr2 = ptr2->next;
        }
        else if(ptr1->e==ptr2->e)
        {
            ptr3->e = ptr1->e;
            ptr3->c = ptr1->c+ptr2->c;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }   
    }
    while(ptr1)
    {
        ptr3 = (node*)malloc(sizeof(node));
        ptr3->next=NULL;
        last3->next=ptr3;
        last3=ptr3;
        ptr3->c=ptr1->c;
        ptr3->e=ptr2->e;
        ptr1=ptr1->next;
    }
    while(ptr2)
    {
        ptr3 = (node*)malloc(sizeof(node));
        ptr3->next=NULL;
        last3->next=ptr3;
        last3=ptr3;
        ptr3->c=ptr2->c;
        ptr3->e=ptr2->e;
        ptr2=ptr2->next;
    }
    ptr3 = head3;
    /*while(ptr3)
    {
        if(ptr3->next==NULL)
        {
            printf("%d.x^%d\n",ptr3->c,ptr3->e );
            break; 
        }
        printf("%d.x^%d + ",ptr3->c,ptr3->e );
        ptr3=ptr3->next;
    }*/
    return head3;
}
int main()
{
    int n,i,j;
    printf("Enter the number of polynomials\n");
    scanf("%d",&n);
    node *p[n],*s[n-1],*ptr;
    for(i=0;i<n;i++)
    {
        p[i]=create();
    }
    s[0]=p[0];
    for(j=1;j<n;j++)
    {
        s[j] = polyadd(s[j-1],p[j]);
    }
    ptr = s[n-1];
    while(ptr)
    {
        if(ptr->next==NULL)
        {
            printf("%d.x^%d\n",ptr->c,ptr->e );
            break; 
        }
        printf("%d.x^%d + ",ptr->c,ptr->e );
        ptr=ptr->next;
    }
    return 0;
}
