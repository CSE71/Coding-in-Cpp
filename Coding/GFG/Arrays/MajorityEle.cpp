//
//  MajorityEle.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 03/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Find largest frequency element (Also must have more elements than n/2)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long int largest(int arr[],int n,int maxnum)
{
    int a[1000001]={0},maxtl=0,maxi;
    for(int i=0;i<n;i++)
    a[arr[i]]++;
    for(int i=0;i<=maxnum;i++)
    if(a[i]>n/2)
    if(maxtl<a[i])
    {
        maxtl = a[i];
        maxi = i;
    }
    if(maxtl>n/2)
    return maxi;
    else
    return -1;
}


int main() {
    //code
    int a,maxi,n;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>n;
        int arr[n],maxnum=0;
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
            maxnum = max(maxnum,arr[j]);
        }
        maxi = largest(arr,n,maxnum);
        cout<<maxi<<"\n";
    }
    return 0;
}
