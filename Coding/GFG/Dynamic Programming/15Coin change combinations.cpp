//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Coin change combinations

//Similar to perfect sums

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
        int n,ele;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            a.push_back(ele);
        }
        int k;
        cin>>k;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(i==0&&j==0)
                dp[i][j]=1;
                
                else if(j==0)
                dp[i][j]=1;
                
                else if(i==0)
                dp[i][j]=0;
                
                else
                {
                    dp[i][j] = dp[i-1][j];
                    if(j>=a[i-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-a[i-1]];
                }
            }
        }
        cout<<dp[n][k]<<endl;
    }
}
