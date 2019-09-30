//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Minimise height of buildings with adding or subtracting k
#include<iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int k,n;
        lli arr[31];
        cin>>k>>n;
        lli sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            
        }
       
        sort(arr,arr+n);
        int ans = arr[n-1] - arr[0];
        int small = arr[0] + k;
    int big = arr[n-1] - k;
    if (small > big)
       swap(small, big);
  
    // Traverse middle elements
    for (int i = 1; i < n-1; i ++)
    {
        int subtract = arr[i] - k;
        int add = arr[i] + k;
  
        // If both subtraction and addition
        // do not change diff
        if (subtract >= small || add <= big)
            continue;
  
        // Either subtraction causes a smaller
        // number or addition causes a greater
        // number. Update small or big using
        // greedy approach (If big - subtract
        // causes smaller diff, update small
        // Else update big)
        if (big - subtract <= add - small)
            small = subtract;
        else
            big = add;
    }
    cout<<min(ans, big - small)<<endl;
    }
}
