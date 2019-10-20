//
//  6.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Rearrange array
// 1,2,3,4,5,6 ---> 6,1,5,2,4,3

#include <iostream>
using namespace std;


void rearrange(long long* arr,int n)
{
    int max_elem = arr[n-1]+1,h=n-1,l=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            arr[i]+=(arr[h]%max_elem)*max_elem;
            h--;
        }
        else
        {
            arr[i]+=(arr[l]%max_elem)*max_elem;
            l++;
        }
    }
    for(int i=0;i<n;i++)
    arr[i]/=max_elem;
}

int main() {
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int j=0;j<n;j++)
        cin>>arr[j];
        rearrange(arr,n);
        for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
        cout<<endl;
    }
}
