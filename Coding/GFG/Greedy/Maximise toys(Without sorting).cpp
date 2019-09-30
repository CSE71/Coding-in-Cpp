//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Maximise toys without sorting
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,k,x;
    cin>>t;
    while(t--)
    {
        int arr[10001]={0};
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            arr[x]++;
        }
        int sum=0;int count=0;
        for(int i=1;i<=k;i++)
        {
            
            if(arr[i]>=1)
            {
                if((sum+i)<=k)
                {
                    int cc=(k-sum)/i;
                    cc=min(cc,arr[i]);// Number of this specific toy to be included
                    count+=cc;
                    sum+=(cc*i);
                }
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}
