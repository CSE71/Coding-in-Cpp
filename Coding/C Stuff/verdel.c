//
//  verdel.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#define SIZE 10


int result[SIZE],k=0;

void verdel(int a[][SIZE],int indeg[SIZE],int n)
{
    int i,st[SIZE],top=-1,node;
    for(i=n-1;i>=0;i--)
    {
        if(indeg[i]==0)
            st[++top]=i;
    }
    
    while(top!=-1)
    {
        node = st[top--];
        result[k++] = node;
        
        for(i=0;i<n;i++)
        {
            if(a[node][i]==1)
            {
                indeg[i]--;
                if(indeg[i]==0)
                    st[++top]=i;
            }
        }
    }
}

int main()
{
    int a[SIZE][SIZE],indeg[SIZE],n;
    
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    
    printf("Enter the adjacency matrix : \n");
    int i,j;
    
    for(i=0;i<n;i++)
        indeg[i]=0;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
                indeg[j]++;
        }
    }
    
    verdel(a,indeg,n);
    
    printf("%d\n",k);
    
    for(i=0;i<k;i++)
    printf("%c ",result[i]+65);
    
    
    
    
    
    
}
