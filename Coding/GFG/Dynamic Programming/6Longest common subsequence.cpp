//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Longest common subsequence
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()

 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));// BASE
        int maxi =0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]= 1 + dp[i-1][j-1];
                    if(maxi<dp[i][j])
                    maxi = dp[i][j];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);// Longest common
                }
            }
        }
        cout<<maxi<<endl;//cout<<dp[n][m]<<endl; Dont really need max. Not applicable for common substring
    }
}
