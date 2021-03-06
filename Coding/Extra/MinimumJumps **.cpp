//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Minimum Jumps

// For an array of numbers, each element represents the maximum number of steps that can be taken to reach the end. Find the minimal number of steps required to reach the end.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mini(vector<int> arr,int n)
{
    if(n<=1)
    return 0;
    
    if(arr[0]==0)
    return -1;
    
    int maxrange = arr[0]; // Points to the highest position that can be jumped to
    int steps = arr[0]; // Steps that can be taken from an element
    int jumps = 1; // Count
    
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        return jumps;
        
        maxrange = max(maxrange,i+arr[i]);
        steps--;
        
        if(steps==0)
        {
            jumps++;
            if(i>=maxrange) // Cannot move from here.
            return -1;
            steps = maxrange - i;
            
        }
    }
    
    
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n,ele;
        vector<int> a;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            a.push_back(ele);
        }
        cout<<mini(a,n)<<endl;
        
    }
}
