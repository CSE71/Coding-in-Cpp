//
//  Number of bribes.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 06/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
void minimumBribes(vector<int> q) {
int ans =0;
    for(int i =q.size()-1;i>=0;i--)
    {
        if(q[i]-(i+1)>2)
        {
            cout<<"Too chaotic"<<endl;
            return;
        }
        for(int j=max(0,q[i]-2);j<i;j++)
        {
            if(q[j]>q[i])
                ans++;
        }
    }
    cout<<ans<<endl;
}
