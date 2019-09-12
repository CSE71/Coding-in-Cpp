//
//  //  Coding
//
//  Created by Surya Dheeshjith on 09/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//PS : Credits to Suhas for making me do this :)

//l -> n, k++
//k ->m, n--
//n-1 -> l, m--
//m-1 ->k, l++
#include <iostream>
using namespace std;


int main()
{
    int k=0,l=0,m,n,cnt=1,m1,n1;
    cin>>m>>n;
    m1=m;n1=n;
    int arr[m][n];
    
    while(k<m && l<n)
    {
        for(int i=l;i<n;i++)
            arr[k][i]=cnt++;
        
        k++;
        
        for(int i=k;i<m;i++)
            arr[i][n-1] = cnt++;
        
        n--;
        
        if(k<m)
        {
            for(int i=n-1;i>=l;i--)
                arr[m-1][i] = cnt++;
            
        }
        m--;
        if(l<n)
        {
            for(int i=m-1;i>=k;i--)
                arr[i][l]=cnt++;
        }
        l++;
        
    }
    for(int i=0;i<m1;i++)
    {
        cout<<endl;
        for(int j=0;j<n1;j++)
            cout<<arr[i][j]<<" ";
    }
}

