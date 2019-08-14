//
//  7.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//


//x^y>y^x

#include<bits/stdc++.h>
using namespace std;

int count(int x, int Y[], int n, int NoOfY[])
{
    if (x == 0) return 0;
    
    if (x == 1) return NoOfY[0];
    
    int* idx = upper_bound(Y, Y + n, x);
    cout<<x<<" "<<idx<<endl;
    int ans = (Y + n) - idx;
    cout<<&Y[n-1]<<endl<<Y+n<<" "<<ans<<endl;
    
    ans += (NoOfY[0] + NoOfY[1]);
    
    if (x == 2)  ans -= (NoOfY[3] + NoOfY[4]);
    
    if (x == 3)  ans += NoOfY[2];
    
    return ans;
}

long long countPairs(int X[], int Y[], int m, int n)
{
    int NoOfY[5] = {0};
    for (int i = 0; i < n; i++)
    if (Y[i] < 5)
    NoOfY[Y[i]]++;
    
    sort(Y, Y + n);
    
    long long total_pairs = 0;
    
    for (int i=0; i<m; i++)
    total_pairs += count(X[i], Y, n, NoOfY);
    
    return total_pairs;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int i,a[m],b[n];
        for(i=0;i<m;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        cout<<countPairs(a, b, m, n)<<endl;
    }
}
