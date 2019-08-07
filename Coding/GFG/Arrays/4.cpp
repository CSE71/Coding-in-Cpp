//
//  4.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 03/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Missing number

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, x;
    cin>>t;
    while(t--)
    {
        int n,res=0;
        cin >> n;
        
        for(int i=1;i<n;i++){
            cin >> x;
            res = res^x;
            res = res^i;
        }
        res = res^n;
        cout<<res<<endl;
    }
    return 0;
}
