//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Knapsack
#include<iostream>
#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
 {
     SPEED;
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n,maxi;
        cin>>n>>maxi;
        vector<int> val;
        vector<int> w;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            val.push_back(ele);
        }
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            w.push_back(ele);
        }
        
        vector<vector<int>> dp(n+1,vector<int>(maxi+1,0)); // BASE
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=maxi;j++)
            {
                dp[i][j] = dp[i-1][j]; // The row before contains the current value of the sack. 
                                        // If it isn't possible to add this current element, just carry forward the value.
                if(j>=w[i-1])
                {
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+val[i-1]); // Need to compare between the current value of knapsack and adding the value 
                                                                            // removing the current object's  weight from the bag. 
                }
               
            }
        }
        cout<<dp[n][maxi]<<endl;
    }
}
