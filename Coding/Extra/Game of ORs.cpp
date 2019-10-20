//

//  Coding
//
//  Created by Surya Dheeshjith on 12/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Game of ORs

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

int sumofors(vector<int> a)
{
    int sum =0 ;
    for(int i=0;i<a.size();i++)
    {
        sum|= a[i];
    }
    return sum;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<int> a(n,0);
        int happy =0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            happy|=a[i];
        }
        
        int prev =0,cur =0;
        sort(a.begin(),a.end(),greater<int>());
        auto x = a.begin();
        while(!a.empty())
        {
            if(x==a.end() && (int)a.size()>0)
            {
                a.erase(a.end()-1);
                happy+=sumofors(a);
                x = a.begin();
                cur =0 ;
                prev =0;
            }
            cur=cur|*x;
            if(cur==prev)
             {
                 int count =0;
                 while(x!=a.end())
                 {
                     int temp = cur;
                     cur|=*x;
                     
                     if(cur==prev)
                     {
                         a.erase(x);
                         count++;
                     }
                     else
                     {
                         cur = temp;
                         x++;
                     }
                 }
                 cur=0;
                 prev=0;
                 x = a.begin();
                 happy+=count*sumofors(a);
             }
             else
             {
                 prev = cur;
                 x++;
             }
        }
        
        cout<<"Happy - " <<happy<<endl;
        
        
    }
   
}

