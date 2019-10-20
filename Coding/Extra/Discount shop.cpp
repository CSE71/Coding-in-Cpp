//

//  Coding
//
//  Created by Surya Dheeshjith on 12/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Discount shop



#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ind =s.size()-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>s[i+1])
            {
                ind = i;
                break;
            }
        }
        int res =0;
        for(int i=0;i<s.size();i++)
        {
            if(i!=ind)
                res=res*10+s[i]-'0';
        }
        cout<<res<<endl;
    }
}

