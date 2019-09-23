
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Sudo Solver

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool zeropresent(int arr[][9],int &row,int &col)
{
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(arr[row][col]==0)
            return true;
        }
    }
    return false;
}
void printsol(int arr[][9])
{
    for(int i=0;i<9;i++)
    {
        
        for(int j=0;j<9;j++)
        cout<<arr[i][j]<<" ";
        
    }
}
bool isValid(int arr[][9],int row,int col,int num)
{
    for(int i=0;i<9;i++)
    {
        if(arr[i][col]==num)
        return false;
    }
    for(int i=0;i<9;i++)
    {
        if(arr[row][i]==num)
        return false;
    }
    int b= row-row%3;
    int l = col - col%3;
    for(int i=b;i<b+3;i++)
    {
        for(int j=l;j<l+3;j++)
        {
            if(arr[i][j]==num)
            return false;
        }
    }
    return true;
}
bool solvesudoku(int arr[][9])
{
    int row,col;
    if(!zeropresent(arr,row,col))
    {
        printsol(arr);
        return true;
    }
    
    else
    {
        for(int i=1;i<=9;i++)
        {
            if(isValid(arr,row,col,i))
            {
                arr[row][col]=i;
                if(solvesudoku(arr))
                return true;
                arr[row][col]=0;
                
            }
        }
    }
    return false; // VVV IMP
    
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int arr[9][9];
        for(int i=0;i<9;i++){
            
            for(int j=0;j<9;j++)
            cin>>arr[i][j];
        
        }
        solvesudoku(arr);
        cout<<endl;
    
    }
    // your code goes here
    return 0;
}
