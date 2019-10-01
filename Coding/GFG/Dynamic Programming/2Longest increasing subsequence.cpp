//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Longest increasing subsequence
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n,ele;
        cin>>n;
        vector<int> num;
        vector<int> a(n,1); // BASE
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            num.push_back(ele);
        }
        int max =1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(num[j]<num[i] && a[i]<a[j]+1)
                {
                    a[i]=a[j]+1;
                    if(max<a[i])
                    max = a[i];
                }
            }
        }
        cout<<max<<endl;
    }
}
