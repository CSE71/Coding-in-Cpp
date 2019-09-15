//
//  //  Coding
//
//  Created by Surya Dheeshjith on 09/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//Find the lth factor of n

#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,l;
    cin>>n>>l; //Element and ith factor of n
    int q = sqrt(n);
    int arr[1000],k=0;
    for(int i=1;i<=q;i++)
    {
        if(n%i==0)
        {
            arr[k++] = i;
        }
    }
    for(int i=0;i<k;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    if(sqrt(n) != (int)sqrt(n))
    {
        if(l>2*k)
        {
            cout<<-1;
        }
        else if(l<=k)
        {
            
            cout<<arr[l-1];
        }
        else
        {
            cout<<n/arr[k-(l-k)];
        }
        
    }
    else
    {
        if(l>2*k+1)
        {
            cout<<-1;
        }
        else if(l<=k)
        {
            
            cout<<arr[l-1];
        }
        else
        {
            cout<<n/arr[k-(l-k)-1];
        }
        
    }
    
    
    
}
