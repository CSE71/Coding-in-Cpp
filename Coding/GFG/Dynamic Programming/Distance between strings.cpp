//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Distance between strings
#include<iostream>
#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int LCS(vector<vector<int>> dp,string a, string b,int m,int n)
{
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            dp[i][j]=j;
            
            else if(j==0)
            dp[i][j]=i;
            
            else if(a[i-1]==b[j-1])
            dp[i][j] = dp[i-1][j-1];
            
            else
            dp[i][j] =1+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
    
    
}
int main()
 {
    SPEED;
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int m,n;
        string a,b;
        cin>>m>>n;
        cin>>a>>b;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        cout<<LCS(dp,a,b,m,n)<<endl;
    }
}
