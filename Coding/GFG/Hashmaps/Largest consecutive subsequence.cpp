//
//  1.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Largest consecutive subsequence
// IP : 2 6 1 9 4 5 3
// OP : 6 // 1,2,3,4,5,6

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
        int m,ele,arr[100001];
        cin>>m;
        unordered_map<int,int> mp;
        //unordered_set<int> mp;
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
            mp[arr[i]]=1;
            //mp.insert(arr[i]);
            
            
        }
        int mcount =-1,count=0;
        for(int i=0;i<m;i++)
        {
            
            count=0;
            if(mp.find(arr[i]-1)==mp.end())
            {
                int j=arr[i];
                while(mp.find(j)!=mp.end())
                {count++;j++;}
                
                if(count>mcount)
                    mcount = count;
            }
            
            
        }
        cout<<mcount<<endl;
        mp.clear();
    }
}
