//
//  1.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Continous Subarray sum 

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
#define pii pair<int,int>
#define mpii(a,b) make_pair(a,b)
using namespace std;

pii findpos(vector<int> a,int k)
{

    int curr=0,start=0;
    for(int i=0;i<a.size();i++)
    {
        curr+= a[i];
        
        while(curr>k)
        {
            curr-= a[start];
            start++;
        }
        
        if(curr==k)
            return mpii(start,i-start+1);
        
        
    }
    return mpii(-1,-1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> a;
        int n;
        cin>>n;
        int k;
        cin>>k;
        for(int i=0;i<n;i++)
        {
            int ele;
            cin>>ele;
            a.push_back(ele);
        }
        
        
        pii p = findpos(a,k);
        if(p.first!=-1)
            cout<<"Start = "<<p.first<<", Length = "<<p.second<<endl;
        
        else
            cout<<"Not found"<<endl;
        
    }
    
}
