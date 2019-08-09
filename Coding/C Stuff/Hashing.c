//
//  9.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 11/11/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

int htable[5]={NULL};

void hinsert(int val)
{
    int i,index,flag=0;
    
    for(i=0;i<5;i++)
    {
        index=(val+i)%5;
        if(htable[index]==-1)
        {
            htable[index]=val;
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Element could not be inserted");
}
void hdelete(int val)
{
    int i,index,flag=0;
    
    for(i=0;i<5;i++)
    {
        index=(val+i)%5;
        if(htable[index]==val)
        {
            htable[index]=-1;
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Element could not be found");
}

void hashsearch(int val)
{
    int i,index,flag=0;
    
    for(i=0;i<5;i++)
    {
        index=(val+i)%5;
        if(htable[index]==val)
        {
            printf("Element found out at index %d",index);
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Element could not be found");
}

void hashdisplay()
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%d \n",htable[i]);
    }
}
int main()
{
    int i,ch,val;
    for(i=0;i<5;i++)
        htable[i]=-1;
    
    while(1)
    {
        printf("Press 1. Insert \t2. Delete \t3. Search \t4.Display \t5. Exit\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: printf("Enter the element\n");
                scanf("%d",&val);
                hinsert(val);
                break;
            case 2: printf("Enter the element\n");
                scanf("%d",&val);
                hdelete(val);
                break;
            case 3: printf("Enter the element\n");
                scanf("%d",&val);
                hashsearch(val);
                break;
            case 4:
                hashdisplay();
                break;
                
            case 5: exit(0);
                
            default: printf("Enter valid choice");
        }
        printf("\n");
        }
