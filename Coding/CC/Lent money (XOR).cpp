//
//  Coding
//
//  Created by Surya Dheeshjith
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


// Maximum XOR -
//https://www.codechef.com/JUNE19B/problems/LENTMO

#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define ull unsigned long long int
#define gcu getchar_unlocked
#define pc(x) putchar(x);
#define pcu(x) putchar_unlocked(x);
#define ll long long int
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007

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
                min=abs(a[i]-(x^a[i]));//Minimum difference when c is odd and need to subtract one xor operation
        }

        if(k%2==1)
            cout<<sx1<<"\n";
        else if(k%2==0&&c%2==0)
            cout<<sx1<<"\n";
        else if(k%2==0&&c%2==1)
            cout<<sx1-min<<"\n";
    }
}
