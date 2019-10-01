
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Maximum elements with copy paste

// 1. Till 6 return the n
// 2. After that find breakpoint using for loop
/*
 
    For n =7,
    i = 6
    j = 3,2,1 (After j, CTRL A, CTRL C, CTRL V*)
    For j =3, curr = 2 x 4 = 8 (A A A A CTRA CTRC CTRV)
    For j =2, curr = 3 x 3 = 9 (A A A CTRA CTRC CTRV CTRV)
    For j = 1, curr = 4 x 2 = 8 (A A CTRA CTRC CTRV CTRV CTRV)
    
 */
#include<iostream>
using namespace std;
int findoptimal(int n)
{
    if(n<=6)
    return n;
    
    int arr[n];
    for(int i=1;i<=6;i++)
    arr[i-1]=i;
    
    for(int i=6;i<n;i++)
    {
        arr[i] = 0;
        for(int j=i-3;j>=1;j--) //CTRL A, CTRL C, CTRL V
        {
            int curr = (i-j-1)*arr[j];
            if(curr>arr[i])
            arr[i] = curr;
            
        }
    }
    return arr[n-1];
}
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        //Enter code here
        int n;
        cin>>n;
        if(n>75)
        cout<<-1<<endl;
        
        else
        {
            cout<<findoptimal(n)<<endl;
        }
    }
}
