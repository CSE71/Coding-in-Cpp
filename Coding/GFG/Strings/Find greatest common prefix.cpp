//
//  12.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Greatest common prefix
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
        int n;
        vector<string> a;
        cin>>n;
        int minn = INT_MAX;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            a.push_back(s);
            minn = min(minn,(int)s.size());
        }
        string res ="";
        int flag=0;
        for(int i=0;i<minn;i++)
        {
            char ch = a[0][i];
            for(int j=0;j<n;j++)
            {
                if(a[j][i]!=ch)
                {
                    flag=1;
                    break;
                }
                
                else if(j==n-1)
                res+=ch;
            }
            if(flag==1)
            break;
        }
        if(res!="")
        cout<<res<<endl;
        else
        cout<<-1<<endl;
    }
}
