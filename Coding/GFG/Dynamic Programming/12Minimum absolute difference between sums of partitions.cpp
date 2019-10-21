//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Minimum absolute difference between sums of partitions
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
        int n,ele,sum=0;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            a.push_back(ele);
            sum+=ele;
        }
        int t= sum/2;
        vector<vector<int>> dp(n+1,vector<int>(t+1));
        for(int i=0;i<=n;i++) // Find maximum value close to sum/2 (Let it be a)
        {
            for(int j=0;j<=t;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
                
                else{
                    dp[i][j] = dp[i-1][j];
                    if(j>=a[i-1])
                    {
                        dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i-1]]+a[i-1]);
                    }
                }
            }
        }
        cout<<sum-2*dp[n][t]<<endl;// a = dp[n][t] ; b = sum - dp[n][t] ; b - a = sum - 2* dp[n][t]
    }
}
