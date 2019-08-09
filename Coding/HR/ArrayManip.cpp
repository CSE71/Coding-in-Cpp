//
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//Array Manipulation
// 5 3 = length of array, queries
//1 2 100
//2 5 100
//3 4 100
//After the first update list will be 100 100 0 0 0.
//After the second update list will be 100 200 100 100 100.
//After the third update list will be 100 200 200 200 100.
//The required answer will be 200

#include <bits/stdc++.h>

using namespace std;

// Complete the arrayManipulation function below.

int main()
{
    int n,k;
    int a,b,c;
    long int max = 0,x=0;
    cin>>n>>k;
    vector<int> arr(n+1,0);
    for(int i=0;i<k;i++)
    {
        cin>>a>>b>>c;
        arr[a]+=c;
        if(b+1<=n)
            arr[b+1]-=c;
        
    }
    for(int i=1;i<=n;i++)
    {
        x +=arr[i];
        if(x>max)
            max =x;
    }
    cout<<max;
    return 0;
}
