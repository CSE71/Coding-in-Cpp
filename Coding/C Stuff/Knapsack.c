//
//  Knapsack.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>

int w[10],prof[10],N,W,C[10][10];


int max(int i,int j)
{
    if(i>j)
        return i;
    else
        return j;
    
}
void knapsack()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<W;j++)
        {
            if(i==0 || j==0)
                C[i][j]=0;
        }
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=W;j++)
        {
            if(j-w[i]<0)
                C[i][j]=C[i-1][j];
            
            else
            {
                C[i][j]= max(C[i-1][j],C[i-1][j-w[i]]+prof[i]);
            }
        }
    }
    
    
    
}

void revengi()
{
    int i=N,j=W;
    
    while(i!=0&&j!=0)
    {
        if(C[i][j]!=C[i-1][j])
        {
            printf("%d %d\n",w[i],prof[i]);
            j=j-w[i];
        }
        i--;
    }
}

int main()
{
    printf("Enter the capacity of bag :");
    scanf("%d",&W);
    
    printf("Enter the number of elements : ");
    scanf("%d",&N);
    
    int i;
    printf("Enter the weights and profits : \n");
    
    for(i=1;i<=N;i++)
    {
        scanf("%d %d",&w[i],&prof[i]);
    }
    
    knapsack();
    printf("Elements to be included -\n");
    revengi();
    printf("Max Capacity : %d\n",C[N][W]);
    
}
