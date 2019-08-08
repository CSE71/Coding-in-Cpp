//
//  Prims.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 29/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#define SIZE 10
#define INF 99

void prims(int C[][SIZE],int n,int s)
{
    int v[SIZE],dist[SIZE],parent[SIZE],U=-1,least,i,j,sum=0;
    
    for(i=0;i<n;i++)
    {
        v[i]=0;
        dist[i]=C[s][i];
        parent[i]=s;
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
        
        sum+=dist[U];
        v[U]=1;
        printf("%d ----> %d Weight = %d Sum = %d \n",parent[U],U,dist[U],sum);
        
        
        for(j=0;j<n;j++)
        {
            if(dist[j]>C[U][j] && v[j]==0)
            {
                dist[j]=C[U][j];
                parent[j]=U;
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
    prims(C,n,s);
}

/*
99 5 1 99
5 99 1 1
1 1 99 5
99 1 5 99
*/
