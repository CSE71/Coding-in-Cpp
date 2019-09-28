//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Select maximum number of activities
#include<iostream>
#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second)
    return a.second<b.second;
    
    return a.first<b.first;
}
int main()
 {
     SPEED;
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n,ele;
        cin>>n;
        vector<int> start;
        vector<int> end;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            start.push_back(ele);
        }
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            end.push_back(ele);
        }
        vector<pair<int,int>> a;
        a.clear();
        for(int i=0;i<n;i++)
        {
            a.push_back(make_pair(start[i],end[i]));
        }
        
        sort(a.begin(),a.end(),compare);
        
        int count=1,i=0,j=1;
        while(i<n && j<n)
        {
            if(a[i].second<=a[j].first)
            {
                count++;
                i = j;
                j++;
            }
            else
            j++;
        }
        
        
        cout<<count<<endl;
    }
}
