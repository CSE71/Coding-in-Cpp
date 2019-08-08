//
//  Floyd's.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#define INF 99
#define SIZE 10

int d[][SIZE];


int min(int i,int j)
{
    if(i<j)
        return i;
    else
        return j;
}
void floyds(int a[][SIZE],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            d[i][j] = a[i][j];
        }
    }
    
    int k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    
    
}

int main()
{
    int n,a[SIZE][SIZE];
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    
    printf("Enter the adjacency matrix : \n");
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    
    floyds(a,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(d[i][j]!=INF)
            printf("%d ",d[i][j]);
            
            else
                printf("INF ");
        }
        printf("\n");
    }
    
}
