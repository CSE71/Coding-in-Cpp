//
//  25.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 08/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Next largest element
//Two methods


//Efficient
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;
unordered_map<long long,long long>mp;
stack<long long>s;
long long arr[10000000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        
        s.push(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i]<s.top())
            s.push(arr[i]);
            else
            {
                
                while(!s.empty()&&s.top()<arr[i])
                {
                    mp[s.top()]=arr[i];
                    s.pop();
                    
                }
                
                s.push(arr[i]);
            }
            
        }
        while(!s.empty())
        {
            mp[s.top()]=-1;
            s.pop();
        }
        
        for(int i=0;i<n;i++)
        cout<<mp[arr[i]]<<" ";
        cout<<endl;
        
        mp.clear();
        while(!s.empty())
        s.pop();
        
        
    }
    return 0;
}







//Naive
/*
#include<iostream>
using namespace std;


void nextLarge(int arr[],int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        flag=0;
        if(i==n-1)
        {
            cout<<"-1";
            return;
        }
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                cout<<arr[j]<<" ";
                flag=1;
                break;
            }
        }
        if(flag==0)
        cout<<"-1 ";
        
    }
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        nextLarge(arr,n);
        cout<<endl;
    }
}
*/
