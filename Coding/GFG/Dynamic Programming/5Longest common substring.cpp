//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Longest common substring
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
        int max =0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]= dp[i-1][j-1]+1;
                    if(max<dp[i][j])
                    max = dp[i][j];
                }
            }
        }
        cout<<max<<endl;
    }
}
