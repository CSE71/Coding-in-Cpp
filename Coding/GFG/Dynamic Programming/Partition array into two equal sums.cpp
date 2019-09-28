//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Can array be partitioned into two equal sums
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
        vector<int> a;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            a.push_back(ele);
            sum+=ele;
        }
        if(sum%2!=0)
        cout<<"NO"<<endl;
        
        else
        {
            //vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));// Giving timeout.
            bool dp[n+1][sum/2+1];
            for(int i=0;i<=n;i++)
            dp[i][0]=true;
            
            for(int i=1;i<=sum/2;i++)
            dp[0][i]=false;
            
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=sum/2;j++)
                {
                   dp[i][j] = dp[i-1][j];
                   if(j>=a[i-1])
                   dp[i][j] = dp[i-1][j]||dp[i-1][j-a[i-1]];
                   
                }
            }
            if(dp[n][sum/2])
            cout<<"YES"<<endl;
            
            else
            cout<<"NO"<<endl;
       }
        
    }
}
