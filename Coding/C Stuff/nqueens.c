//
//  nqueens.c
//  DAAExternals
//
//  Created by Surya Dheeshjith on 29/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#include<math.h>

int board[10],count=0;

void printsol(int n)
{
    printf("Solution %d :\n",count+1);
    count++;
    int i;
    printf("\t");
    for(i=1;i<=n;i++)
        printf("%d\t",i);
    
    int j;
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",i);
        for(j=1;j<=n;j++)
        {
            
            if(board[i]==j)
            {
                printf("Q\t");
            }
            
            else
            {
                printf("-\t");
            }
            
        }
        printf("\n");
    }
}

int place(int row,int column)
{
    int i;
    for(i=1;i<=row-1;i++)
    {
        if(board[i]==column)
            return 0;
        else if(abs(board[i]-column) == abs(i-row))
            return 0;
        
    }
    return 1;
}
void queens(int row,int n)
{
    int column;
    for(column = 1;column<=n;column++)
    {
        if(place(row,column))
        {
            board[row]=column;
            
            if(row == n)
            {
                printsol(n);
            }
            else
            {
                queens(row+1,n);
            }
        }
    }
}
int main()
{
    
    int n;
    printf("Enter the number of queens : ");
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
        board[i]=0;
    queens(1,n);
    
}
