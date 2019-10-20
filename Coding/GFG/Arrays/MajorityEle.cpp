//
//  MajorityEle.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 03/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Find largest frequency element (Also must have more elements than n/2)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int> a;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            a.push_back(ele);
            if(mp.find(ele)==mp.end())
                mp[ele]=1;
            else
                mp[ele]++;
            
        }
        int max=-1;
        for(auto x=mp.begin();x!=mp.end();x++)
        {
            if(max<x->second && x->second>n/2)
                max = x->second;
        }
        cout<<max<<endl;
    }
}
