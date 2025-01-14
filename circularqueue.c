#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int front=-1,rear=-1,queue[20],size,num;
void insert();
void display();
void delete();
void reverse();



void insert()
{
    
    printf("\nEnter the element to insert : ");
    scanf("%d",&num);
    if((rear+1)%size == front)
    {
        printf("\nOverflow condition");
    }
    else
    {
        if(front==-1)
        {
        front=0;
        rear=0;
        }
       else
        {
           rear=(rear+1)%size;
        }
        queue[rear]=num;
        printf("\n %d element inserted",num);

    } 
}

void delete()
{
    
    if(front==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        num=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
        printf("Deleted element is %d",num);
    }
}

void display()
{
   
    if(front==-1)
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        printf("\t%d",queue[rear]);
    }
    else
    {
         printf("\nCircular queue elements are : ");
        for(int i=front;i<=rear;i++)
        {
            printf("\t%d",queue[i]);
        }
    }
}

void reverse()
{
    if(front==-1)
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        printf("\t%d only single element",queue[rear]);
    }
    else
    {
        printf("\nCircular reversed queue elements are : ");
        for(int i=rear;i>=front;i--)
        {
            printf("\t%d",queue[i]);
        }
    }

}

void main()
{
    int choice;
    printf("\nEnter the size of the queue : ");
    scanf("%d",&size);
    printf("\nCIRCULAR QUEUE");
    int flag=1;
    while(flag)
    {
        printf("\n1.insert \n2.delete \n3.display \n4.reverse \n5.exit");
        printf("\nEnter your choice  : ");
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
            reverse();
            break;

            case 5:
            flag=0;
            break;

            default:
            printf("\nEnter a valid choice");
            break;
        }
    }
}