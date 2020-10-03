//Menu driven program for linkedlist with implementation of different funtions

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int value;
    struct Node* next;  
};
typedef struct Node node;

node* Insert_beginning(node* s,int n)
{
    node* q;
    q=(node*)malloc(sizeof(node));
    q->value=n;
    q->next=s;
    s=q;
    return s;
}

node* Insert_End(node* s,int n)
{
    node* q;
    node* p;
    q=(node*)malloc(sizeof(node));
    q->value=n;
    q->next=NULL;
    if(s==NULL) s=q;
    else
    {
        p=s;
        while(p->next!=NULL) p=p->next;
        p->next=q;
    }
    return s;
}
void Display(node* s)
{
    node* p;
    if(s==NULL) printf("List is Empty\n");
    else
    {
        p=s;
        while(p!=NULL)
        {
            printf("%d ",p->value);
            p=p->next;
        }
        printf("\n");
    } 
}
node* Insert_afelement(node* s,int a,int n)
{
    node* q;
    node* p;
    q=(node*)malloc(sizeof(node));
    q->value=a;
    if(s==NULL) printf("List is Empty\n\n");
    else
    {
        p=s;
        while(p->value!=n && p->next!=NULL)
        {
            p=p->next;
        }
        if(p->value==n)
        {
            q->next=p->next;
            p->next=q;
        }
    }
    return s;
}
node* Delete(node* s,int n)
{
    node* q;
    node* p;
    if(s==NULL) printf("List is Empty\n\n");
    else
    {
        q=s;
        while(q!=NULL && q->value!=n)
        {
            p=q;
            q=q->next;
        }
        if(q!=NULL)
        {
            if(q==s)
            {
                s=s->next;
            }
            else
            {
                p->next=q->next;
            }
            free(q);

        }
    }
    return s;   
}
int Count_node(node* s)
{
    node* p;
    int Count=0;
    p=s;
    while(p!=NULL)
    {
        p=p->next;
        Count++;
    }
    return Count;
}
int Maximum(node* s)
{
    int max=-100000;
    node* p;
    if(s==NULL) printf("List is Empty\n\n");
    else
    {
        p=s;
        while(p!=NULL)
        {
            if(max<p->value) max=p->value;
            p=p->next;
        }
    }
    return max;
}
int Minimum(node* s)
{
    int min=100000000;
    node* p;
    if(s==NULL) printf("List is Empty\n\n");
    else
    {
        p=s;
        while(p!=NULL)
        {
            if(min > p->value) min=p->value;
            p=p->next;
        }
    }
    return min;
}

int Search(node* s,int a)
{
    node* q;
    q=s;
    int count=1;
    while(q!=NULL && q->value!=a)
    {
        q=q->next;
        count++;
    }
    if(q!=NULL) return count;
    else return 0;
}

int main()
{
    int n,a,b;
    node* start;
    start=NULL;
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
                start=Insert_beginning(start,a);
                break;
            }
            case 2:
            {
                printf("Enter value to Insert\n");
                scanf("%d",&a);
                start=Insert_End(start,a);
                break;
            }
            case 3:
            {
                printf("Enter value to Insert and element after which value is to be Inserted\n");
                scanf("%d%d",&a,&b);
                start=Insert_afelement(start,a,b);
                break;
            }
            case 4:
            {
                printf("Enter value to Delete\n");
                scanf("%d",&a);
                start=Delete(start,a);
                break;
            }
            case 5:
            {
                Display(start);
                printf("\n");
                break;
            }
            case 6:
            {
                printf("Number of nodes %d\n\n",Count_node(start));
                break;
            }
            case 7:
            {
                if(start==NULL) printf("List is Empty\n");
                else printf("Maximum number is %d\n\n",Maximum(start));
                break;
            }
            case 8:
            {
                if(start==NULL) printf("List is Empty\n");
                else printf("Minimum number is %d\n\n",Minimum(start));
                break;
            }
            case 9:
            {
                printf("Enter value to Search\n");
                scanf("%d",&a);
                b=Search(start,a);
                if(b) printf("Number is Present at %d node\n\n",b);
                else printf("Not Present\n\n");
                break;
            }
            case 10: return 0;
            default : printf("Enter valid choice\n\n");
        }
    }
}