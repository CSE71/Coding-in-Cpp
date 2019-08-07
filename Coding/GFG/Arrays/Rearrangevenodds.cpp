//
//  Rearrangevenodds.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 11/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//


//Rearrange such that even numbers come in even indices and odd numbers come in odd indices with relative positioning same and using O(1) space.
#include<iostream>
using namespace std;



void rearrange(int arr[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        if(i%2==0 && arr[i]%2!=0)
        {
            
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]%2==0)
                {
                    temp = arr[j];
                    for(int k=j;k>i;k--)
                        arr[k] = arr[k-1];
                    break;
                }
                
            }
            arr[i]=temp;
        }
        else if(i%2!=0 && arr[i]%2==0)
        {
            
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]%2!=0)
                {
                    temp = arr[j];
                    for(int k=j;k>i;k--)
                        arr[k] = arr[k-1];
                    break;
                }
                
            }
            arr[i]=temp;
        }
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
        rearrange(arr,n);
        for(int k=0;k<n;k++)
            cout<<arr[k]<<" ";
        cout<<endl;
    }
}

