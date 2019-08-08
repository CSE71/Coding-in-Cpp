//
//  Djikstras.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 29/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//


#include <stdio.h>
#define SIZE 10
#define INF 99

int dist[SIZE];
void djikstras(int C[][SIZE],int n,int s)
{
    int v[SIZE],U=-1,least,i,j;
    
    for(i=0;i<n;i++)
    {
        v[i]=0;
        dist[i]=C[s][i];
    }
    
    v[s]=1;
    
    for(i=1;i<n;i++)
    {
        least = INF;
        for(j=0;j<n;j++)
        {
            if(least>dist[j] && v[j]==0)
            {
                least = dist[j];
                U = j;
            }
        }
        
        v[U]=1;
        
        for(j=0;j<n;j++)
        {
            if(dist[j]>dist[U]+C[U][j])
            {
                dist[j]=C[U][j] + dist[U];
                
            }
        }
    }
}

int main()
{
    int s,n,C[SIZE][SIZE];
    int i,j;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    
    printf("Enter the matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&C[i][j]);
        }
    }
    printf("Enter the source vertex : ");
    scanf("%d",&s);
    
    djikstras(C,n,s);
    
    for(i=0;i<n;i++)
    {
        if(i!=s)
        {
            printf("Distance from %d to %d is %d\n",s,i,dist[i]);
        }
    }
    
}
