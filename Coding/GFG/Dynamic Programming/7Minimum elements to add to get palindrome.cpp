//
//  12.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//Minimum elements to add to get palindrome

//Maximum common subsequence of string and reverse + n-length
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
        string s;
        cin>>s;
        string w=s;
        reverse(w.begin(),w.end());
        vector<vector<int>>dp(w.size()+1,vector<int>(s.size()+1));// BASE
        for(int i=0;i<=w.size();i++)
        {
            for(int j=0;j<=w.size();j++)
            {
                if(i==0||j==0)
                dp[i][j]=0;// BASE
                
                else
                {
                    if(s[i-1]==w[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                    
                    else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
               }
            }
        }
        
        cout<<s.size()-dp[s.size()][s.size()]<<endl;
    }
}
