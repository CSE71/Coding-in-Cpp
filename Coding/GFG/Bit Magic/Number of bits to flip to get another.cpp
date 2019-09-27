
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Number of bits to flip to get another number
#include<iostream>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int m,n;
        cin>>m>>n;
        m = m^n;
        int count =0;
        while(m)
        {
            count+=1 & m;
            m>>=1;
        }
        cout<<count<<endl;
    }
}
