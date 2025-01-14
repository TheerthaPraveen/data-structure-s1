#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
int num,pos;

void insert();
void display();
void delete();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void reverse();

void insert()
{
    int choice;
    printf("\n1.insertion at beginnimg \n2.insertion at end \n3.insertion at position");
    printf("\nenter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insert_beg();
        break;

        case 2:
        insert_end();
        break;

        case 3:
        insert_pos();
        break;

        default:
        printf("\nEnter a valid choice ");
        break;


    }
}


void insert_beg()
{
    printf("\nEnter the value to be inserted : ");
    scanf("%d",&num);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
        tail=newnode;
    }
    else
    {
        struct node *temp=head;
        newnode->prev=NULL;
        newnode->next=temp;
        head=newnode;
        temp->prev=newnode;


    }
    printf("\nInsertion sucessfull");
    
}

void insert_end()
{
    printf("\nEnter the value to be inserted : ");
    scanf("%d",&num);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL)
    {
        insert_beg();
    }
    else
    {
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
        printf("\nInsertion sucessfull at end");
    }
}

void insert_pos()
{
    printf("\nEnter the position to be inserted : ");
    scanf("%d",&pos);
    printf("\nEnter the value to be inserted : ");
    scanf("%d",&num);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL)
    {
        insert_beg();
    }
    else
    {
        struct node *temp=head;
        struct node *nextnode;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        nextnode=temp->next;
        newnode->prev=temp;
        newnode->next=nextnode;
        temp->next=newnode;
        nextnode->prev=newnode;
        printf("\nInsertion sucessfully at position %d",pos);
    }
}

void delete()
{
    int choice;
    printf("\n1.deletion at beginning \n2.deletion at end \n3.deletion at pos");
    printf("\nEnter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        delete_beg();
        break;

        case 2:
        delete_end();
        break;

        case 3:
        delete_pos();
        break;

        default:
        printf("\nEnter a valid choice ");
        break;
    }
}


void delete_beg()
{
    int num;
    if(head==NULL){
        printf("\nLIST IS EMPTY");
    }
    else if(head==tail)
    {
        num=head->data;
        head->prev=NULL;
        printf("\nData deleted is %d",num);
    }
    else
    {
        struct node *temp=head;
        struct node *second;
        second=temp->next;
        num=temp->data;
        second->prev=NULL;
        head=second;
        printf("\nData deleted is %d",num);
    }
    
}

void delete_end()
{
    int num;
    if(head==NULL){
        printf("\nLIST IS EMPTY");
    }
    else if(head==tail)
    {
        num=head->data;
        head->prev=NULL;
        printf("\nData deleted is %d",num);
    }
    else
    {
        struct node *temp;
        temp=tail->prev;
        num=tail->data;
        tail->prev=NULL;
        tail=temp;
        temp->next=NULL;
        printf("\nData deleted is %d",num);

    }


}

void delete_pos()
{
    int num,pos;
    printf("\nEnter the positio you want to delete : ");
    scanf("%d",&pos);
    if(head==NULL){
        printf("\nLIST IS EMPTY");
    }
    else
    {
        struct node *temp=head;
        struct node *current;
        struct node *nextnode;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        current=temp->next;
        nextnode=current->next;
        num=current->data;
        temp->next=current->next;
        nextnode->prev=temp;
        printf("\n%d deleted from position %d",num,pos);

    }

}

void reverse()
{
    printf("\nDisplaying the reverse ");
    if(head==NULL){
        printf("\nLIST IS EMPTY");
    }
    else
    {
        struct node *temp=tail;
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->prev;
        }
    }

}



void display()
{
    if(head==NULL && tail==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }
    }
}




void main()
{
    printf("\nDOUBLY LINKED LIST OPERATIONS");
    int flag=1;
    int op;
    while(flag)
    {
        printf("\n1.insert \n2.delete \n3.display \n4.reverse \n5.exit");
        printf("\nEnter any one operation : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            reverse();
            break;

            case 5:
            flag=0;
            break;

            default:
            printf("\nEnter a valid operation");
            break;
        }
    }
}