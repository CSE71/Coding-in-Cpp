
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Relative Sort based on another array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


unordered_map<int,int> mp;
int search(int a)
{
    if(mp.find(a)!=mp.end())
        return mp[a];
    
    return -1;
}
bool compare(int a,int b)
{
    int idx1 = search(a);
    int idx2 = search(b);
    if(idx1==-1 && idx2==-1)
    {
        return a<b;
    }
    else if(idx1!=-1 && idx2==-1)
        return 1;
    
    else if(idx2!=-1 && idx1==-1)
        return 0;
    
    else
        return idx1<idx2;
    
    
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int m,n,ele;
        vector<int> a,b;
        
        cin>>m>>n;
        for(int i=0;i<m;i++)
        {
            cin>>ele;
            a.push_back(ele);
        }
        
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            b.push_back(ele);
            mp[b[i]] = i;
            
        }
        sort(a.begin(),a.end(),compare);
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        
        cout<<endl;
        a.clear();
        b.clear();
        mp.clear();
    }
}
