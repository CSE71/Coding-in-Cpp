//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Minimum Coins (Can use same mu;ltiple times)
//1, 2, 5, 10, 20, 50, 100, 200, 500, 2000

#include<iostream>
#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int arr[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} ;
void solvemincoins(int n)
{
    vector<vector<int>>a(11,vector<int>(n+1,0));

    
    for(int i=1;i<=n;i++)
    {
        a[1][i] = i;// For 1
    }
    for(int i=2;i<=10;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j] = a[i-1][j];
            if(j>=arr[i-1])
            a[i][j] = min(a[i-1][j],a[i][j-arr[i-1]]+1);// Same row cause multiple of same currency can be used.
        }
    }
    
    int i=10,j=n;
    while(i!=0&&j!=0)
    {
        if(a[i][j]!=a[i-1][j])
        {
            cout<<arr[i-1]<<" ";
            j = j-arr[i-1];
        }
        else
        i--;
    }
}
int main()
 {
     SPEED;
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n;
        cin>>n;
        solvemincoins(n);
        cout<<endl;
    }
}
