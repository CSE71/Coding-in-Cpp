
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
// Kth largest element in stream
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
        priority_queue<int,vector<int>,greater<int>> pq;
        int k,n,ele;
        cin>>k>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ele;
            if(pq.size()<k)
                pq.push(ele);


            else
            {
                if(ele>pq.top())
                {
                    pq.pop();
                    pq.push(ele);

                }
            }

            if(pq.size()<k)
                cout<<-1<<" ";

            else
                cout<<pq.top()<<" ";

        }
        cout<<endl;
    }
}
