//
//  12.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//Longest distinct substring
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
        string s;
        cin>>s;
        vector<int> a(26,-1);
        int start =0,end =0,maxx=-1;
        for(int i=0;i<s.size();i++)
        {
            if(a[s[i]-'a']==-1)
            {
                a[s[i]-'a']=i;
                end++;
            }
            else
            {
                if(start>a[s[i]-'a'])
                {
                    a[s[i]-'a'] = i;
                    end++;
                }
                else
                {
                    start = a[s[i]-'a']+1;
                    a[s[i]-'a'] = i;
                    end++;
                }
                
                
            }
            maxx = max(maxx,end-start);
            
        }
        cout<<maxx<<endl;
    }
}
