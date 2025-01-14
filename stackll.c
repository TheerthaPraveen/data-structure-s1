#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int num;


void push();
void display();
void pop();
void reverse();


void push()
{
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&num);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
    printf("\nData inserted ");
    
}

void display()
{
    if(head==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("\nStack elements are : ");
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->next;

        }
    }
}

void pop()
{
    int num;
    if(head==NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        struct node *temp=head;
        num=temp->data;
        head=temp->next;
        temp->next=NULL;
        printf("\nDeleted element is %d",num);

        
    }
}

void reverse(struct node *temp)
{
    if(temp==NULL)
    return;
    reverse(temp->next);
    printf("\t%d",temp->data);
}

void main()
{
    int choice;
    printf("\nStack using linked list");
    int flag=1;
    while(flag)
    {
        printf("\n1.push \n2.pop \n3.display \n4.reverse \n5.exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
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

// void search()
// {
//     if (head == NULL)
//     {
//         printf("\nStack is empty");
//         return;
//     }

//     int value;
//     printf("\nEnter the element to search: ");
//     scanf("%d", &value);

//     struct node *temp = head;
//     int pos = 1;

//     while (temp != NULL)
//     {
//         if (temp->data == value)
//         {
//             printf("\nElement %d found at position %d", value, pos);
//             return;
//         }
//         temp = temp->next;
//         pos++;
//     }

//     printf("\nElement %d not found in the stack", value);
// }

// void sort_ascending()
// {
//     if (head == NULL || head->next == NULL)
//     {
//         printf("\nStack is empty or has only one element. No sorting needed.");
//         return;
//     }

//     struct node *i, *j;
//     int temp;

//     for (i = head; i != NULL; i = i->next)
//     {
//         for (j = i->next; j != NULL; j = j->next)
//         {
//             if (i->data > j->data)
//             {
//                 temp = i->data;
//                 i->data = j->data;
//                 j->data = temp;
//             }
//         }
//     }

//     printf("\nStack sorted in ascending order.");
// }

// void sort_descending()
// {
//     if (head == NULL || head->next == NULL)
//     {
//         printf("\nStack is empty or has only one element. No sorting needed.");
//         return;
//     }

//     struct node *i, *j;
//     int temp;

//     for (i = head; i != NULL; i = i->next)
//     {
//         for (j = i->next; j != NULL; j = j->next)
//         {
//             if (i->data < j->data)
//             {
//                 temp = i->data;
//                 i->data = j->data;
//                 j->data = temp;
//             }
//         }
//     }

//     printf("\nStack sorted in descending order.");
// }