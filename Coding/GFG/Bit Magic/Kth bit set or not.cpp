
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Kth bit set or not
#include <bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t; // Inputting testcases
    while(t--)
    {
        long long n;
        cin>>n;
        int k;
        cin>>k;
        if((n&(1<<(k)))!=0) // Move 1 to kth bit and do a bitwise AND to check if bit is set.
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
    return 0;
}
