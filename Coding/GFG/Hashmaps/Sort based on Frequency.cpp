//
//  1.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Sort Based on frequency. If higher freq, comes before. if same, increasing order sort.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int findfreq(int a)
{
    if(mp.find(a)!=mp.end())
        return mp[a];
    
    return -1;
}
bool compare(int a,int b)
{
    int freq1 = findfreq(a);
    int freq2 = findfreq(b);
    if(freq1==freq2)
        return a<b;
    
    else
        return freq1>freq2;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int m,ele;
        cin>>m;
        vector<int> a;
        for(int i=0;i<m;i++)
        {
            cin>>ele;
            a.push_back(ele);
            mp[ele]++;
        }
        sort(a.begin(),a.end(),compare);
        for(int i=0;i<m;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        mp.clear();
        a.clear();
    }
}
