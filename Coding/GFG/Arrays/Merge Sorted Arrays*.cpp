//
//  5*.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Merge two sorted arrays in O((n+m)log(n+m)) with space efficiency O(1)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr1[10000001],arr2[10000001];

int nextgap(int gap)
{
    if(gap<=1)
    return 0;
    return gap/2 + gap%2;
}

void merge(int n,int m)
{
    int gap = n+m,i,j;
    for(gap = nextgap(gap);gap>0;gap = nextgap(gap))
    {
        for(i=0;i+gap<n;i++)
        {
            if(arr1[i]>arr1[i+gap])
            {
                swap(arr1[i],arr1[i+gap]);
            }
        }
        for(j= gap>n?gap-n:0;i<n && j<m;i++,j++)
        {
            if(arr1[i]>arr2[j])
            {
                swap(arr1[i],arr2[j]);
            }
        }
        
        if(j<m)
        {
            for(j=0;j+gap<m;j++)
            {
                if(arr2[j]>arr2[j+gap])
                {
                    swap(arr2[j],arr2[j+gap]);
                }
            }
        }
    }
}
int main() {
    
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        int n,m;
        cin>>n>>m;
        for(int j=0;j<n;j++)
        cin>>arr1[j];
        for(int j=0;j<m;j++)
        cin>>arr2[j];
        merge(n,m);
        for(int j=0;j<n;j++)
        cout<<arr1[j]<<" ";
        for(int j=0;j<m;j++)
        cout<<arr2[j]<<" ";
        cout<<endl;
        
    }
    
    
    return 0;
}
