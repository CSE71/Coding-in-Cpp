//
//  Long Factorials.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
void extraLongFactorials(int n) {
    
    vector<int> a;
    a.push_back(1);
    for(int i=2;i<=n;i++)
    {
        for(auto x= a.begin();x!=a.end();x++)
        {
            *x *= i;
        }
        for(int q =0;q<a.size();q++)
        {
            if(a[q]<10)
                continue;
            
            if(q == a.size()-1)
            {
                a.push_back(0);
            }
            a[q+1] += a[q]/10;
            a[q]=a[q]%10;
        }
        
    }
    
    for(auto x=a.rbegin();x!=a.rend();x++)
    {
        cout<<*x;
    }
    
}
