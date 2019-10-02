//
//  //  Coding
//
//  Created by Surya Dheeshjith on 09/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Min adjacent swaps to sort Binary
// IP : 1001011 --> 0001111,  OP: 4


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
            a[i]++;   // Stores number of zeros from right
        
    }
    int count =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
            count+=a[i];  // Number of zeros to cross for each one
    }
    
    return count;
}
