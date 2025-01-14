#include<stdio.h>
#include<stdbool.h>

int arr[100],n,choice,num,pos ;


void insert()
{
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&num);
    printf("\nEnter the position to be inserted : ");
    scanf("%d",&pos);
    for(int i=n;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    n++;
    printf("\nInserted element");

}

void delete()
{
    printf("\nEnter the position to be deleted : ");
    scanf("%d",&pos);
    for(int i=pos-1;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    printf("\nDeleted sucessfully");

    
}

void search()
{
    int s;
    printf("\nEnter the element to be searched : ");
    scanf("%d",&s);
    for(int i=0;i<n;i++)
    {
        if(s==arr[i])
        {
            printf("\nThe element found at %d",i+1);
        }
        else
        {
            printf("\nItem not found");
        }
    }
    
}

void sort()
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-1)-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            

        }
    }
    
}

void display()
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}

void reverse()
{
    for(int i=n-1;i>=0;i--)
    {
        printf("%d\t",arr[i]);
    }
}



void merge()
{
    int n2,arr2[100]={0},n3,arr3[200] ;
    printf("\nEnter the size of second array : ");
    scanf("%d",&n2);
    printf("\nEnter the elements of second array : ");
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&arr2[i]);
    }

    n3=n+n2;

    for(int i=0;i<n;i++)
    {
        arr3[i]=arr[i];
    }
    for(int i=0;i<n2;i++)
    {
        arr3[i+n]=arr2[i];
    }

    printf("\nThe merged array");
    for(int i=0;i<n3;i++)
    {
        printf("%d",arr3[i]);
    }

    printf("\nReversed merged array");
    {
        for(int i=n3-1;i>=0;i--)
        {
            printf("%d",arr3[i]);
        }
    }

    
}



void main()
{
    int flag=1;
    printf("\nEnter the array size : ");
    scanf("%d",&n);
    if(n>100 || n<=0)
    {
        printf("Invalid size");
        printf("\nRe-enter the array size : ");
        scanf("%d",&n);
    }
    printf("\nEnter the array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nARRAY OPERATIONS");
    while(flag)
    {
    printf("\n1.insertion \n2.deletion \n3.search \n4.sort \n5.display \n6.merge \n7.exit");
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
        search();
        break;

        case 4:
        sort();
        break;

        case 5:
        display();
        break;

        case 6:
        merge();
        break;

        case 7:
        flag=0;
        break;

        default:
        printf("\nEnter a valid choice");
        break;
    }
    }

}