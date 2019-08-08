//
//  Binomial.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 28/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>

int min(int i,int j)
{
    if(i<j)
        return i;
    else
        return j;
}

void binomial(int n,int k)
{
    int i,j;
    int C[20][20];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            if(j==0 || i==j)
                C[i][j]=1;
            
            else
            {
                C[i][j] = C[i-1][j]+C[i-1][j-1];
            }
        }
    }
    printf("%d",C[n][k]);
}

int main()
{
    int n,k;
    printf("Enter n and k : ");
    scanf("%d %d",&n,&k);
    binomial(n,k);
    
}
