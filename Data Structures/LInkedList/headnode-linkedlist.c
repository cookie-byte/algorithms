//Menu driven program for linkedlist with headnode 
//implementation of different funtions

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node;

struct headnode
{
    node* start;
    node* end;
};
typedef struct headnode head;

void Insert_beginning(head* h,int x)
{
    node* q;
    q=(node*)malloc(sizeof(node));
    q->data=x;
    if(h->start==NULL)
    {
        q->next=h->start;
        h->start=q;
        h->end=q;
    }
    else
    {
        q->next=h->start;
        h->start=q;  
    }
}

void Insert_End(head* h,int x)
{
    node* q;
    q=(node*)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    if(h->start==NULL)
    {
        h->start=q;
        h->end=q;
    }
    else
    {
        h->end->next=q;
        h->end=q;
    }
}

void Display(head h)
{
    if(h.start==NULL) printf("List is empty\n");
    else
    {
        while(h.start!=NULL)
        {
            printf("%d  ",h.start->data);
            h.start=h.start->next;
        }
        printf("\n");
    }
}

void Insert_afelement(head* h,int a,int n)
{
    node* q;
    node* p;
    q=(node*)malloc(sizeof(node));
    q->data=a;
    if(h->start==NULL) printf("List is Empty\n\n");
    else
    {
        p=h->start;
        while(p->data!=n && p->next!=NULL)
        {
            p=p->next;
        }
        if(p==h->end)
        {
           q->next=p->next;
           p->next=q;
           h->end=q;   
        }
        else if(p->data==n)
        {
            q->next=p->next;
            p->next=q;
        }
    }
}

void Delete(head* h,int a)
{
    node* p;
    node* q;
    q=h->start;
    while(q->data!=a && q->next!=NULL)
    {
        p=q;
        q=q->next;
    }
    if(q==h->end && q->data==a)
    {
        p->next=q->next;
        h->end=p;
        free(q);
    }
    else if(q->next!=NULL)
    {
        if(q==h->start)
        {
            h->start=q->next;
        }
        else
        {
            p->next=q->next;
        }
        free(q);
    }
    else printf("Element is not Present in List\n");
}

int Count_node(head* h)
{
    int Count=0;
    node* p=h->start;
    while(p!=h->end)
    {
        Count++;
        p=p->next;
    }
    return ++Count;
}
int Maximum(head* h)
{
    int max=-100000;
    node* p=h->start;
    while(p!=NULL)
    {
        if(max<p->data) max=p->data;
        p=p->next;
    }
    return max;
}

int Minimum(head* h)
{
    int min=100000;
    node* p=h->start;
    while(p!=NULL)
    {
        if(min > p->data) min=p->data;
        p=p->next;
    }
    return min;
}

int Search(head* h,int a)
{
    node* p;
    p=h->start;
    int count=1;
    while(p!=NULL && p->data!=a)
    {
        p=p->next;
        count++;
    }
    if(p!=NULL) return count;
    else return 0;
}

int main()
{
    head h;
    int n,a,b;
    h.start=NULL;
    h.end=NULL;
    while(1)
    {
        printf("Enter 1 to Insert at Beginning\n");
        printf("Enter 2 to Insert at End\n");
        printf("Enter 3 to Insert After an element\n");
        printf("Enter 4 to Delete a node\n");
        printf("Enter 5 to Display List\n");
        printf("Enter 6 to Count Nodes\n");
        printf("Enter 7 to Find Maximum\n");
        printf("Enter 8 to Find Minimum\n");
        printf("Enter 9 to Search value\n");
        printf("Enter 10 to Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                printf("Enter value to Insert\n");
                scanf("%d",&a);
                Insert_beginning(&h,a);
                break;
            }
            case 2:
            {
                printf("Enter value to Insert\n");
                scanf("%d",&a);
                Insert_End(&h,a);
                break;
            }
            case 3:
            {
                printf("Enter value to Insert and element after which value is to be Inserted\n");
                scanf("%d%d",&a,&b);
                Insert_afelement(&h,a,b);
                break;
            }
            case 4:
            {
                printf("Enter value to Delete\n");
                scanf("%d",&a);
                Delete(&h,a);
                break;
            }
            case 5:
            {
                Display(h);
                printf("\n");
                break;
            }
            case 6:
            {
                printf("Number of nodes %d\n\n",Count_node(&h));
                break;
            }
            case 7:
            {
                if(h.start==NULL) printf("List is Empty\n");
                else printf("Maximum number is %d\n\n",Maximum(&h));
                break;
            }
            case 8:
            {
                if(h.start==NULL) printf("List is Empty\n");
                else printf("Minimum number is %d\n\n",Minimum(&h));
                break;
            }
            case 9:
            {
                printf("Enter value to Search\n");
                scanf("%d",&a);
                b=Search(&h,a);
                if(b) printf("Number is Present at %d node\n\n",b);
                else printf("Not Present\n\n");
                break;
            }
            case 10: return 0;
            default : printf("Enter valid choice\n\n");
        }
    }
}