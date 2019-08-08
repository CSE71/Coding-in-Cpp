//
//  dfsbfs.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#define SIZE 10

void dfs(int a[][SIZE],int v[],int n, int s)
{
    int i;
    v[s] = 1;
    printf("%d ",s+1);
    
    for(i=0;i<n;i++)
    {
        if(v[i]==0 && a[s][i]==1)
            dfs(a,v,n,i);
        
    }
}

void bfs(int a[][SIZE],int v[],int n,int s)
{
    int q[SIZE],f=0,r=-1,node,i;
    v[s]=1;
    q[++r] = s;
    
    while(f<=r)
    {
        node = q[f++];
        printf("%d ",node+1);
        for(i=0;i<n;i++)
        {
            if(v[i]==0 && a[node][i]==1)
            {
                v[i]=1;
                q[++r]=i;
            }
        }
    }
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
    
    
    printf("DFS - \n");
    for(i=0;i<n;i++)
    {
        v[i]=0;
    }
    int count =0;
    
    for(i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            dfs(a,v,n,i);
            count++;
            printf("\n");
            
        }
    }
    if(count == 1)
        printf("\nConnected \n");
    else
        printf("\nDisconnected %d\n",count);
    
    printf("BFS - \n");
    for(i=0;i<n;i++)
    {
        v[i]=0;
    }
    count =0;
    
    for(i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            bfs(a,v,n,i);
            count++;
            printf("\n");
        }
    }
    if(count == 1)
        printf("\nConnected \n");
    else
        printf("\nDisconnected %d\n",count);
    
    
}
