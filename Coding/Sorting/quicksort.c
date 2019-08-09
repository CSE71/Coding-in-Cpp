//
//  quicksort.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

int count=0;

int partition(int a[],int low,int high)
{
    int i=low+1,j=high,p=a[low],temp;
    
    while(1)
    {
        while(i<high && a[i]<=p)
        {
            count++;
            i++;
        }
        
        while(j>low && a[j]>=p)
        {
            count++;
            j--;
        }
        
        count++;
        if(i<j)
        {
            //count++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            
        }
        else{
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}



void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int j = partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int main()
{
    int a[1050],b[1050],c[1050],n,c1,c2,c3;
    printf("Sample Run \n");
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements :\n");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n------------------\n");
    printf("N\tASC\tDESC\tRAND\n");
    int j;
    for(i=16;i<1050;i*=2)
    {
        for(j=0;j<i;j++)
        {
            a[j] = j;
            b[j] = i-j -1;
            c[j] = rand()%(i+1);
        }
        
        count =0;
        quicksort(a,0,i-1);
        c1 = count;
        
        count =0;
        quicksort(b,0,i-1);
        c2 = count;
        
        count =0;
        quicksort(c,0,i-1);
        c3 = count;
        
        printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
    }
    
}
