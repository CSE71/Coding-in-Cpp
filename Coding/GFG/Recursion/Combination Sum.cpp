
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Find combinations in array to get a sum
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int flag=0;
void combination(int l,int curr,int sum,vector<int> a,set<vector<int>> &arr,vector<int> res)
{
    if(curr==sum)
    {
        flag=1;
        arr.insert(res);
        
    }
    
    else
    {
        for(int i=l;i<a.size();i++)
        {
            if(curr+a[i]>sum)
            continue;
            
            res.push_back(a[i]);
            combination(i+1,curr+a[i],sum,a,arr,res);
            res.pop_back();
        }
    }
    
}
void combo(vector<int> a,int sum)
{
    sort(a.begin(),a.end());
    set<vector<int>> arr;
    vector<int> res;
    combination(0,0,sum,a,arr,res);
    for(auto i =arr.begin();i!=arr.end();i++)
    {
        cout<<"(";
        const vector<int> &l=*i;//WOW
        for(int j=0;j<(int)l.size();j++)
        {
            if(l.size()-1==j)
            cout<<l[j];
            
            else
            cout<<l[j]<<" ";
        }
        cout<<")";
    }
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        flag=0;
        int n,ele,sum;
        vector<int> a;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            a.push_back(ele);
        }
        cin>>sum;
        combo(a,sum);
        if(flag==0)
        cout<<"Empty"<<endl;
        
        else
        cout<<endl;
       
    }
}
