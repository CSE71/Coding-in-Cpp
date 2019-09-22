
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Largest subarray that sums upto k

#include<bits/stdc++.h>
using namespace std;

int lenofLongSubarray(vector<int> a, int n,int k)
{
    unordered_map<int,int> mp;
    int maxlen=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+= a[i];
        if(sum == k)
            maxlen = i+1;
        
        if(mp.find(sum)==mp.end())
        {
            mp[sum]=i;
        }
        if(mp.find(sum-k)!=mp.end())
        {
            maxlen = max(maxlen,i-mp[sum-k]);
        }
    }
    return maxlen;
}
