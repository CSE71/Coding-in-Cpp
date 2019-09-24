//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Finding medium efficiently

int getmed(vector<int> count,int d)
{
    vector<int>freq(count);
    for(int i=1;i<201;i++)
    {
        freq[i]+=freq[i-1];
    }
    int med,a1=0,b1=0;
    
    if(d%2==0)
    {   int i=0;
        for(;i<201;i++)
        {
            if(freq[i]>=d/2)
            {
                a1=i;
                break;
            }
        }
        for(;i<201;i++)
        {
            if(freq[i]>=d/2+1)
            {
                b1=i;
                break;
            }
        }
    }
    else
    {
        for(int i=0;i<201;i++)
        {
            if(freq[i]>=d/2+1)
            {a1=2*i;
                break;}
        }
    }
    
    return a1+b1;
}
int activityNotifications(vector<int> a, int d) {
    
    int ret=0;
    vector<int> count(201,0);
    for(int i=0;i<d;i++)
        count[a[i]]++;
    
    for(int i=d;i<a.size();i++)
    {
        int med = getmed(count,d);
        if(a[i]>=med)
            ret++;
        
        count[a[i-d]]--;
        count[a[i]]++;
    }
    return ret;
}
