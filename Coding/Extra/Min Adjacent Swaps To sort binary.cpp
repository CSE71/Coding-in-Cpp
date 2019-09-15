//
//  //  Coding
//
//  Created by Surya Dheeshjith on 09/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Min and Max of three numbers without conditional statements

#include<iostream>
using namespace std;

int swaps(int arr[],int n)
{
    vector<int> a(n,0);
    
    a[n-1] = 1-arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        a[i] = a[i+1];
        if(arr[i]==0)
            a[i]++;
        
    }
    int count =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
            count+=a[i];
    }
    
    return count;
}
