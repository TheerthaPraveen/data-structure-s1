#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

int num;

void enqueue();
void display();
void reverse();
void dequeue();
void search();
void sort();


void enqueue()
{
    printf("\nEnter the data to be inserted : ");
    scanf("%d",&num);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL)
    {
       newnode->next=NULL;
       head=newnode;
       tail=newnode;
       
    }
    else
    {
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
        

    }
    printf("\nInserton sucess");

}

void dequeue()
{
    int num;
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else if(head==tail)
    {
        num=head->data;
        head=NULL;
        tail=NULL;
        printf("\nThe deleted number is %d",num);
    }
    else
    {
        struct node *temp=head;
        num=temp->data;
        head=head->next;
        printf("\nThe deleted number is %d",num);

    }
    
}



void display()
{
    if(head==NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nDisplay elements ");
       struct node *temp=head;
       while(temp!=NULL)
        {
        printf("\t%d",temp->data);
        temp=temp->next;
        }
    }
    
}

void reverse(struct node *temp)
{
    if(temp==NULL)
    return;
    reverse(temp->next);
    printf("\t%d",temp->data);
}

void search()
{
    int value;
    if(head==NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nEnter the element to be searched : ");
        scanf("%d",&value);
        struct node *temp=head;
        int pos=1;
        while(temp!=NULL)
        {
            if(temp->data==value)
            {
                printf("Element found at position %d",pos);
            }
            temp=temp->next;
            pos++;
        }
        printf("\nelement not found");

    }
}

void sort()
{
    struct node *i,*j;
    int temp;
    for(i=head;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data > j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;

            }
        }
    }
    printf("Stack is sorted");
}

void main()
{
    int choice;
    printf("\nStack using linked list");
    int flag=1;
    while(flag)
    {
        printf("\n1.enqueue \n2.dequeue \n3.display \n4.reverse \n5.search \n6.sort \n7.exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;

            case 2:
            dequeue();
            break;

            case 3:
            display();
            break;

            case 4:
            reverse(head);
            break;

            case 5:
            search();
            break;

            case 6:
            sort();
            break;

            case 7:
            flag=0;
            break;

            default:
            printf("\nEnter a valid option");
            break;

        }
    }
}
