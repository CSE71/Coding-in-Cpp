//
//  main.c
//  Escapingsoldiers.c
//
//  Created by Surya Dheeshjith on 17/02/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#include<math.h>

#define SIZE 100

void dfs(int a[][SIZE],int v[],int n,int s)
{
    int i;
    v[s]=1;
    printf("%d - >",s);
    for(i=0;i<n;i++)
    {
        if(v[i]==0&&a[s][i]==1)
        {
            dfs(a,v,n,i);
        }
    }
}


int main()
{
    
    int n,l,w,i,j,x1,y1,v[50],start[50],end[50],k=0,p=0;
    double length;
    scanf("%d %d %d",&l,&w,&n);
    int x[n],y[n],a[n][n];
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        v[i]=0;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x1 = x[i]-x[j];
            y1 = y[i]-y[j];
            length = x1*x1+y1*y1;
            
            if(i!=j&&length<=40000)
            {
                printf("(%d , %d) = %lf ;",i,j,sqrt(length));
                a[i][j]=1;
            }
            
            else
            a[i][j]=0;
        }
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        if(w-y[i]<=100)
        {
            start[k++]=i;
            printf("s- %d ",i);
        }
        
        if(y[i]<=100)
        {
            end[p++]=i;
            printf("e - %d ",i);
        }
    }
    /*
    for(i=0;i<k;i++)
    {
        printf("%d ",start[i]);
        
    
    }
    printf("\n");
    for(i=0;i<p;i++)
    {
        printf("%d ",end[i]);
        
    }
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    */
    
    
    
    printf("\n");
    int f=0;
    for(i=0;i<k;i++)
    {
        
        if(v[start[i]]==0)
        {
            dfs(a,v,n,start[i]);
            
        }
        
        
    }
    
    for(j=0;j<p;j++)
    {
        if(v[end[j]]==1)
        {
            f=1;
            printf("\n1");
            break;
            
        }
    }
    
    
    if(f==0)
        printf("\n0");
    
    
}
