//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Maximum sum uncreasing subsequence
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
        int n;
        cin>>n;
        vector<int> a;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            a.push_back(ele);
        }
        for(int i=0;i<n;i++)
        dp[i] = a[i];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j] && dp[i]<a[i]+dp[j])
                dp[i] = dp[j]+a[i];
                
            }
        }
        int max=-1;
        for(int i=0;i<n;i++)
        {
            if(max<dp[i])
            max = dp[i];
        }
        cout<<max<<endl;
    }
}
