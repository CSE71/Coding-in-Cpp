//
//  dfstopo.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#define SIZE 10

int st[SIZE],top=-1;

void dfs(int a[][SIZE],int v[],int n,int s)
{
    
    int i;
    v[s] = 1;
    
    for(i=0;i<n;i++)
    {
        if(v[i]==0 && a[s][i]==1)
            dfs(a,v,n,i);
    }
    
    st[++top] = s;
}


int main()
{
    int a[SIZE][SIZE],v[SIZE],n;
    
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    
    printf("Enter the adjacency matrix : \n");
    int i,j;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    
    for(i=0;i<n;i++)
        v[i]=0;
    
    for(i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            dfs(a,v,n,i);
        }
    }
    
    
    printf("%d\n",top);
    printf("Topological order : ");
    for(i=top;i>=0;i--)
        printf("%c ",st[i]+65);
    
    
}
