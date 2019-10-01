#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void Finsert(struct node** pointerToHead , int x)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data= x;
    //temp->next = NULL;
    // if(head!=NULL)
    temp->next = *pointerToHead;
    *pointerToHead = temp;
}
void Rinsert(struct node** head , int x)
{
    struct node* temp ;
    temp = ( struct node* ) malloc ( sizeof ( struct node ) );
    temp->data = x;
    temp->next = NULL;
    struct node* itr = *head;
    if(*head==NULL)
    {
        *head=temp;
        return;
    }
    while(itr->next!=NULL)
    {
        itr=itr->next;
    }
    itr->next=temp;
}
void Minsert(struct node** head , int x  , int pos)
{
    struct node* itr =*head;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=x;
    if(pos==1)
    {
        temp->next=*head;
        *head=temp;
        return;
    }
    for(int i=1 ; i<= (pos-2) ; i++)
    {
        itr=itr->next;
    }
    temp->next= itr->next;
    itr->next=temp;
}
void Fdelete(struct node** head)
{
    struct node* temp;
    temp=*head;
    *head=temp->next;
}
void Mdelete(struct node** head, int pos)
{
    struct node* temp;
    temp=*head;
    if(pos==1)
    {
        *head=temp->next;
        return;
    }
    for(int i=1 ;i <= pos-2;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
}
void Rdelete(struct node** head)
{
    struct node* temp;
    temp=*head;
    if(temp->next==NULL)
    {
        *head=NULL;
        return;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
void Display(struct node** head)
{
    struct node* temp = *head;
    printf("List is : ");
    while(temp!=NULL)
    {
        printf(" %d" , temp->data);
        temp= temp->next;
    }
    printf("\n");
}
int main()
{
    int n,i,x, choice , pos, del;
    struct node* head=NULL;                                               // list is empty
    printf("How many number you want to insert? \n");
    scanf("%d" , &n);
    for (int i = 0; i <n ; ++i) {
        choices:
        printf("1. Front Insert  2. Middle Insert 3. Rear Insert\n4. Front Delete  5. Middle Delete  6. Rear Delete\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("Enter number : \n");
                scanf("%d", &x);
                Finsert(&head,x);
                Display(&head);
                break;
            }
            case 2:
            {
                printf("Enter number : \n");
                scanf("%d", &x);
                printf("Enter position where you wanna insert : \n");
                scanf("%d", &pos);
                Minsert(&head , x, pos);
                Display(&head);
                break;
            }
            case 3:
            {
                printf("Enter number : \n");
                scanf("%d", &x);
                Rinsert(&head , x);
                Display(&head);
                break;
            }
            case 4:
            {
                Fdelete(&head);
                Display(&head);
                break;
            }
            case 5:
            {
                printf("Which position of element you want to delete\n");
                scanf("%d",&del);
                Mdelete(&head,del);
                Display(&head);
                break;
            }
            case 6:
            {
                Rdelete(&head);
                Display(&head);
                break;
            }
            default: printf("***Choose correct option***\n");
                goto choices;
        }

    }
}
