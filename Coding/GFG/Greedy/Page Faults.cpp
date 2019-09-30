//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Page faults with LRU
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int faults(vector<int> a,int n, int cap)
{
    unordered_set<int> s;
    unordered_map<int,int> mp;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(s.size()<cap)
        {
            if(s.find(a[i])==s.end())
            {
                s.insert(a[i]);
                mp[a[i]]=i;
                count++;
            }
            else
            mp[a[i]]=i;
        }
        else
        {
            if(s.find(a[i])==s.end())
            {
                int min =INT_MAX,mini;
                for(auto x=s.begin();x!=s.end();x++)
                {
                    if(min>mp[*x])
                    {
                        min = mp[*x];
                        mini = *x;
                    }
                }
                s.erase(mini);
                s.insert(a[i]);
                mp[a[i]] = i;
                count++;
            }
            else
            {
                mp[a[i]] = i;
            }
        }
    }
    return count;
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n;
        vector<int> a;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            a.push_back(ele);
        }
        int cap;
        cin>>cap;
        cout<<faults(a,n,cap)<<endl;
        
    }
}
