
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//N queens
#include<iostream>
using namespace std;
int flag=0;
int place(int board[],int row,int col)
{
    for(int i=1;i<row;i++)
    {
        if(board[i]==col)
        return 0;
        
        if(abs(board[i]-col) == abs(i-row))
        return 0;
    }
    return 1;
}
void queens(int board[],int row,int n)
{
    int col;
    for(col=1;col<=n;col++)
    {
        if(place(board,row,col))
        {
            board[row] = col;
        
            if(row==n)
            {
                flag=1;
                cout<<"[";
                for(int i=1;i<=n;i++)
                {
                    cout<<board[i]<<" ";
                }
                cout<<"] ";
            
            }
            else
            queens(board,row+1,n);
        }
    }
}
int main()
 {
    int t;
    cin>>t;
    int board[11];
    while(t--)
    {
        //Enter code here
        int n;
        cin>>n;
        flag=0;
        for(int i=1;i<=n;i++)
        board[i]=0;
        queens(board,1,n);
        if(flag==0)
        cout<<-1;
        
        cout<<endl;
    }
}
