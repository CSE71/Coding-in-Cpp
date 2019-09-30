//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Coin piles (Minimum number of coins to remove so the difference between each pile is <= k)
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
        int n,k,ele;
        cin>>n>>k;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            a.push_back(ele);
            
        }
        int prev=0;
        int rem =0;
        int minn=INT_MAX;
        sort(a.begin(),a.end());
        for(int i=0;i<n-1;i++)
        {
            rem = prev;
            prev+=a[i]; // Stores previous coin piles sum
            
            for(int j=n-1;j>i;j--)
            {
                if(a[j]-a[i]-k>0)
                rem+=a[j]-a[i]-k; // Adds the differences
                
            }
            minn = min(minn,rem);
        }
        cout<<minn<<endl;
        
    }
}
