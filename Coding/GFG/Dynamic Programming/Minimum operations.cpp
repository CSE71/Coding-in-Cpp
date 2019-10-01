//
//  1.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Min operations to get 0.
//Divide and Subtract.
//1. FOR 1 JUST SUBTRACT AND THEN DIVIDE TO GET N-1 BITS; FOR 0 JUST DIVIDE.
#include<iostream>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int m;
        cin>>m;
        int total=0,set=0;
        while(m)
        {
            if(m%2==1)
            set++;
            
            total++;
            m=m/2;
        }
        cout<<total+set-1<<endl;
    }
}

//2.

#include<iostream>
#include<bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main()
 {
     SPEED;
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int m;
        cin>>m;
        vector<int> a(m+1,0);
        a[1]=1;
        for(int i=2;i<=m;i++)
        {
            if(i%2)//odd
            a[i]=a[i-1]+1;
            
            else
            {
                a[i] = a[i/2]+1;
            }
        }
        cout<<a[m]<<endl;
    }
}
