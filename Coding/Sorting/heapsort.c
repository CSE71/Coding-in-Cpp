//
//  heapsort.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>

int len,count =0;

void heapify(int a[],int i)
{
    int k=i,v= a[i],flag =0,j;
    
    while(!flag && 2*k<=len)
    {
        count++;
        j = 2*k;
        
        if(j<len)
        {
            if(a[j+1]>a[j])
                j = j+1;
        }
        
        if(v>=a[j])
            flag=1;
        
        else
        {
            a[k]=a[j];
            k=j;
        }
        
    }
    a[k]=v;
}

void heapsort1(int a[])
{
    int temp,i;
    count++;
    
    for(i=len/2.0;i>=1;i--)
    {
        heapify(a,i);
    }
    
    for(i=len;i>=2;i--)
    {
        count++;
        temp = a[i];
        a[i]=a[1];
        a[1]=temp;
        len--;
        heapify(a,1);
    }
    
    
    
}

int main()
{
    int a[1050],b[1050],c[1050],n,c1,c2,c3;
    printf("Sample Run : \n");
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    int i;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    len = n;
    heapsort1(a);
    
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n------------------\n");
    printf("N\tASC\tDESC\tRAND\n");
    int j;
    for(i=16;i<1050;i*=2)
    {
        for(j=1;j<=i;j++)
        {
            a[j]=j;
            b[j]=i-j+1;
            c[j] = rand()%(j+1);
        }
        
        len =i;
        count =0;
        heapsort1(a);
        c1 = count;
        
        len =i;
        count =0;
        heapsort1(b);
        c2 = count;
        
        len =i;
        count =0;
        heapsort1(c);
        c3 = count;
        
        printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
        
        
    }
    
}
