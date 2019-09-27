
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Find if sparse. (No consecutive ones)
#include<iostream>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n & (n>>1)) // Right shift the number, AND with itself if there is some output number is not sparse.
        cout<<"0"<<endl;
        else
        cout<<"1"<<endl;
    }
    return 0;
}
