//
//  mergesort.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

int count =0;

void merge(int a[],int low,int mid,int high)
{
    int i=low,k=low,j=mid+1,b[1050];
    while(i<=mid && j<=high)
    {
        
        count++;
        if(a[i]<a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i<=mid)
    {
        count++;
        b[k++] = a[i++];
    }
    while(j<=high)
    {
        count++;
        b[k++] = a[j++];
    }
    
    for(i=low;i<=high;i++)
    {
        a[i] = b[i];
    }
}


void mergesort1(int a[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergesort1(a,low,mid);
        mergesort1(a,mid+1,high);
        merge(a,low,mid,high);
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
    mergesort1(a,0,n-1);
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
            c[j] = rand()%(j+1);
        }
        
        count =0;
        mergesort1(a,0,i-1);
        c1 = count;
        
        count =0;
        mergesort1(b,0,i-1);
        c2 = count;
        
        count =0;
        mergesort1(c,0,i-1);
        c3 = count;
        
        printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
    }
    
    
    
    
}
