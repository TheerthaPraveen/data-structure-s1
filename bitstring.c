#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void main()
{
    int n,universalset[20],i,j,n1,n2,set1[10],set2[10],bitvectot1[10],bitvector2[10],unionset[20],interset[20];
    int flag=1;

    //universal set
    printf("\nEnter the size of universal set : ");
    scanf("%d",&n);
    printf("\nEnter the elements of universal set :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&universalset[i]);
    }
    printf("\nThe universal set is :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",universalset[i]);
    }


    //input the set1

    printf("\nEnter the size of first set");
    scanf("%d",&n1);
    printf("\nEnter the elements of first set : ");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&set1[i]);
    }
    printf("\nSet1: ");
    for (i = 0; i < n1; i++)
    {
        printf("\t%d", set1[i]);
    }

    for(int i=0;i<n;i++)
    {
        bitvectot1[i]=0;
        for(int j=0;j<n1;j++)
        {
            if(universalset[i] == set1[j])
            {
                bitvectot1[i]=1;
                break;
            }
        }
    
    }
    printf("\nBit vector for set1: ");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d",bitvectot1[i]);
    }



    //input set 2
    printf("\nEnter the size of second set : ");
    scanf("%d",&n2);
    printf("\nEnter the elements for second set : \n");
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&set2[i]);
    }
    printf("\nSet2 is: \n");
    for(int i=0;i<n2;i++)
    {
        printf("\t%d",set2[i]);
    }

    for(int i=0;i<n;i++)
    {
        bitvector2[i]=0;
        for(int j=0;j<n2;j++)
        {
            if(universalset[i]== set2[j])
            {
                bitvector2[i]=1;
                break;
            }
        }
    }
    printf("\nBit vector for set2 is :\n");
    for(int i=0;i<n;i++)
    {
        printf("\t%d",bitvector2[i]);
    }



    while(flag)
    {
        int choice;
        printf("\n\nMenu:");
        printf("\n1. UNION");
        printf("\n2. INTERSECTION");
        printf("\n3. DISPLAY UNION");
        printf("\n4. DISPLAY INTERSECTION");
        printf("\n5. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            for(int i=0;i<n;i++)
            {
                unionset[i]=bitvectot1[i] | bitvector2[i];
            }
            printf("\nUnion Calculated");
            break;

            case 2:
            for(int i=0;i<n;i++)
            {
                interset[i] = bitvectot1[i] & bitvector2[i] ;
            }
            printf("\nIntersection calculated");
            break;

            case 3:
            printf("\nUnion bit vector");
            for(int i=0;i<n;i++)
            {
                printf("%d\t",unionset[i]);
            }
            printf("\n");
            break;


            case 4:
            printf("Intersection bit vector: ");
            for (i = 0; i < n; i++)
            {
                printf("%d\t",interset[i]);
            }
            printf("\n");
            break;

            case 5:
            // Exit program
            flag=0;
            printf("Exiting program.\n");
            break;
            
            default:
            printf("Invalid choice. Please try again.\n");
            break;


        }

    }

}