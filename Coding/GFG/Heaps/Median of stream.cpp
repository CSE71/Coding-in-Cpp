
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Find median of stream of numbers
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
priority_queue<int> maxi;
priority_queue<int,vector<int>,greater<int>> mini;
void balance_heaps()
{
    while(abs(maxi.size()-mini.size())>1)
    {
        if(maxi.size()>mini.size())
        {
            mini.push(maxi.top());
            maxi.pop();
        }
        else
        {
            maxi.push(mini.top());
            mini.pop();
        }
    }
}
void insert_heaps(int ele)
{
    if(maxi.empty())
    maxi.push(ele);
    
    else if(ele>maxi.top())
    mini.push(ele);
    
    else
    maxi.push(ele);
        
    balance_heaps();
}
int median_heaps()
{
    if(maxi.size()==mini.size())
    return (maxi.top()+mini.top())/2;
    
    else if(maxi.size()>mini.size())
    return maxi.top();
    
    else
    return mini.top();
}


int main()
 {
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        insert_heaps(ele);
        cout<<median_heaps()<<endl;
    }
    
}
