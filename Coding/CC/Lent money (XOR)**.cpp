//
//  Coding
//
//  Created by Surya Dheeshjith
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


// Maximum XOR -
//https://www.codechef.com/JUNE19B/problems/LENTMO
//Credits to Sparsh and Vishak

// N sized array of elements
// Given an integer k and X
// Maximise the sum if XOR of X with exactly k elements at a time is possible
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    SPEED
    ll t,n,i,s,sx,x,k,sx1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        s=0;sx=0;
        sx1=0;
        ll a[n+1];

        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s=s+a[i];
        }

        cin>>k>>x;

        if(x==0)
        {
            cout<<s<<"\n";
            continue;
        }

        if(k==n)
        {
            for(i=0;i<n;i++)
           {
            sx=sx+(x^a[i]);
           }
            cout<<max(s,sx)<<"\n";
            continue;
        }

        ll c=0;
        ll min=INT_MAX;

        for(i=0;i<n;i++)
        {
            sx1=sx1+max(a[i],(x^a[i]));
            if(a[i]<(x^a[i]))
            {
                c++;
            }
            if(min>abs(a[i]-(x^a[i])))
                min=abs(a[i]-(x^a[i]));//Minimum difference required when c is odd and need to subtract/add one xor operation to make it even.
        }

        if(k%2==1)// If odd, any number of XOR operations is possible (1,2,3,... or any integer). K is redundant
            cout<<sx1<<"\n";
        else if(k%2==0&&c%2==0) // If k is even, even number of xor operations is possible.
            cout<<sx1<<"\n";
        else if(k%2==0&&c%2==1) // So when we have odd number of numbers which have their XORed operation greater, we reduce by the least difference between the number and its xored value.
            cout<<sx1-min<<"\n";
    }
}
