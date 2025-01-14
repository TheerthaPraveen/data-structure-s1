#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int num,pos;
void insert_beg();
void insert_end();
void insert_pos();
void insert();
void display();
void delete();
void delete_beg();
void delete_end();
void delete_pos();
void reverse();



void delete()
{
    int option;
    printf("\n1.delete at begining \n2.delete at end \n3.delete at pos");
    printf("\nEnter any one option");
    scanf("%d",&option);
    switch(option)
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
        printf("\nEnter a valid option");
        break;
    }
}

void delete_beg()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *temp=head;
        num=temp->data;
        head=temp->next;
        temp->next=NULL;
        printf("\nElement deleted is %d",num);
        

    }

}

void delete_end()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *temp=head;
        struct node *prev;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        num=temp->data;
        prev->next=NULL;
        printf("\nDeleted element is %d",num);
    }

}

void delete_pos()
{
    printf("\nEnter the position to be deleted : ");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *temp=head;
        struct node *current;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        current=temp->next;
        num=current->data;
        temp->next=current->next;
        printf("\ndeletion successfull at position %d",pos);

        
    }

}



void insert()
{
    int option;
    printf("\n1.insert at begining \n2.insert at end \n3.insert at pos");
    printf("\nEnter any one option");
    scanf("%d",&option);
    switch(option)
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
        printf("\nEnter a valid option");
        break;
    }
}

void insert_beg()
{
    printf("\nEnter the data to be inserted : ");
    scanf("%d",&num);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    printf("\nInserton sucess");

}

void insert_end()
{
    printf("\nEnter the data to be inserted : ");
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
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->next=NULL;
        temp->next=newnode;
        printf("\ninsertion sucess");
    }
    

}

void insert_pos()
{
    printf("\nEnter the position to be inserted : ");
    scanf("%d",&pos);
    printf("\nEnter the data to be inserted : ");
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
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        printf("\nData inserted at postion %d",pos);
    }
}


void display()
{
    if(head==NULL)
    {
        printf("\nList is empty");

    }
    else
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        
        
    }
}

void reverse( struct node *temp)
{
    if(temp == NULL)
        return;
    reverse(temp->next);  // Recursive call
    printf("%d\t", temp->data);   // Print data after returning from the recursive call
}


void main()
{
    printf("\nLinked LIST");
    int flag=1;
    int choice;
    while(flag)
    {
        printf("\n1.Insert \n2.delete \n3.display \n4:reverse \n5.exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
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
            reverse(head);
            break;

            case 5:
            flag=0;
            break;

            default:
            printf("\nEnter a valid option");
            break;
        }
    }
}
