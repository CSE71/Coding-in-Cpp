//
//  31.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 09/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//First non repeating element
// Given a stream of characters, find the first non-repeating character from stream.
// You need to tell the first non-repeating character in O(1) time at any moment.

#include<iostream>
#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;
void checkme(char arr[],int n)
{
    int flag=0;
    unordered_map<char,int> mp;

    for(int i=97;i<=122;i++)
    mp[char(i)]=0;

    for(int i=0;i<n;i++)
    {
        flag=0;
        mp[arr[i]] +=1;
        //cout<<mp[arr[i]];

        for(int j=0;j<=i;j++)
        {
            if(mp[arr[j]]==1)
            {
                cout<<arr[j]<<" ";
                flag=1;
                break;
            }
        }
        if(flag==0)
        cout<<-1<<" ";

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
        char arr[n];


        for(int i=0;i<n;i++)
        cin>>arr[i];


        checkme(arr,n);
        cout<<endl;
        //Enter code here
    }
}
