
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Rotate left and right. Given 16 bits.
#include<iostream>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        unsigned short int m,k,ans;// TYPE IS IMP
        cin>>m>>k;
        k = k %16;
        ans = (m<<k) | (m>>(16-k));
        cout<<ans<<endl;
        ans = (m>>k) | (m<<(16-k));
        cout<<ans<<endl;
        
        
    }
}
