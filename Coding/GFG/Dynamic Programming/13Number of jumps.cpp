//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Number of ways frog jumps possible with 1,2,3 to reach top(n).
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long a[n];
        a[0]=1;
        a[1]=1;
        a[2]=2;
        for(int i=3;i<n;i++)
        {
            a[i]=a[i-1]+a[i-2]+a[i-3];  // Add the number of ways to reach 1, 2 and 3 less than N.
        }
        printf("%ld\n",a[n-1]);
    }
    return 0;
}
