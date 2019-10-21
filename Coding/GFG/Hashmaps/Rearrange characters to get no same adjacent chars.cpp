
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Rearrange Characters to get no same adjacent characters

#include<iostream>
#include<bits/stdc++.h>
#include<string>
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
        int n;
        n = s.length();
        int max =-1;
        char c;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
           mp[s[i]]++;
            if(mp[s[i]]>max)
            {
                max = mp[s[i]];
            }
        }
        if(max==1)
        {
            cout<<1<<endl;
        }
        else
        {
            if(n%2==0)
            {
                if(n/2>=max)
                cout<<1<<endl;
                
                else
                cout<<0<<endl;
            }
            else
            {
                if((n+1)/2>=max)
                cout<<1<<endl;
                
                else
                cout<<0<<endl;
            }
            
        }
    }
}
