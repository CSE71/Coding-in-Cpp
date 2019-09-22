
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//All pairs must be divisible by k

// Use remainders
// 1. if rem==0, must have even number of elements with rem =0
// 2. if rem*2 == k , then there must be even number of elements with rem*2 = k
// 3. Else freq of rem = freq of (k - rem) : 5 = 2+3 , 12+3==> 2%5 = 2, 3%5 =3, 12%5 = 2, 3%5=3
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
        int n,k,ele;
        vector<int> a;
        a.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            a.push_back(ele);
            
        }
        cin>>k;
        
        if(n & 1)
        {
            cout<<"False"<<endl;
            continue;
        }
        unordered_map<int,int> mp;
        mp.clear();
        for(int i=0;i<n;i++)
            mp[a[i]%k]++;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            int rem = a[i]%k;
            if(rem==0)
            {
                if(mp[rem]&1!=0)
                {
                    cout<<"False"<<endl;
                    flag=1;
                    break;
                }
            }
            else if(rem*2==k)
            {
                if(mp[rem] &1!=0)
                {
                    cout<<"False"<<endl;
                    flag=1;
                    break;
                }
            }
            else if(mp[rem]!=mp[k-rem])
            {
                cout<<"False"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"True"<<endl;
        
        
    }
    
}
