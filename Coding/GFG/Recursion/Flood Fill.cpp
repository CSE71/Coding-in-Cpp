
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 80
#define M 80
int n,m;
void floodfillutil(int a[][M],int x, int y, int old, int k)
{
    if(x<0 || y<0 || x>=n || y>=m)
    return;
    
    if(a[x][y]!=old)
    return;
    
    a[x][y] = k;
    floodfillutil(a,x-1,y,old,k);
    floodfillutil(a,x,y+1,old,k);
    floodfillutil(a,x+1,y,old,k);
    floodfillutil(a,x,y-1,old,k);
    
}
void floodfill(int a[][M],int x, int y, int k)
{
    int old = a[x][y];
    return floodfillutil(a,x,y,old,k);
    
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        
        cin>>n>>m;
        int a[N][M];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cin>>a[i][j];
        }
        int x,y,k;
        cin>>x>>y>>k;
        floodfill(a,x,y,k);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
        
    }
}
