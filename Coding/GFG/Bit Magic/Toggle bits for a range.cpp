
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Toggle bits of range
#include<iostream>
#include<math.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,l,r;
        cin>>n>>l>>r;
        int num = (pow(2,r)-1) - (pow(2,l-1)-1);
        num = num^n;
        cout<<num<<endl;
        
        //Enter code here
    }
}
