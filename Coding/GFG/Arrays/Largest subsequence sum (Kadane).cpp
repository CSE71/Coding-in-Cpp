//
//  3.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 03/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//

//Largest subsequence sum

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

long int largest(int arr[],int n)
{
    int maxh=0,maxf=-10000000;
    for(int i=0;i<n;i++)
    {
        maxh +=arr[i];
        maxf = max(maxf,maxh);
        if(maxh<0)
        maxh=0;
    }
    return maxf;
    
}

int main() {
    //code
    long int a,maxi,n;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        maxi = largest(arr,n);
        cout<<maxi<<"\n";
    }
    return 0;
}
