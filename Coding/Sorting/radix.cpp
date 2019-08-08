//
//  radix.cpp
//  DAAC++
//
//  Created by Surya Dheeshjith on 01/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
#include<iostream>
#define FULL 30

using namespace std;


// A utility function to get maximum value in A[]
int getMax(int A[], int n)
{
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}

//Count_Sort is used as a Sub-routine to radix sort

int tc = 0;

void Count_Sort(int A[], int n, int exp)
{
    int B[FULL];
    int C[10] = {0};
    int i;
    
    for (i = 0; i < n; i++)
        C[ (A[i]/exp)%10 ]++;
    
    for (i = 1; i < 10; i++)
        C[i] += C[i - 1];
    
    for (i = n - 1; i >= 0; i--)
    {
        B[C[ (A[i]/exp)%10 ] - 1] = A[i];
        C[ (A[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        A[i] = B[i];
}


int dig_len=0;

void radixsort(int A[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(A, n);
    
    
    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        Count_Sort(A, n, exp);
        dig_len++;
    }
}

int main()
{
    int n;
    int k;
    cout<<"\nRadix Sort\n------------------";
    cout<<"\nEnter the size of the array :";
    cin>>n;
    /*A stores the elements input by user */
    /*B stores sorted Aay of elements*/
    int A[FULL],B[FULL];
    
    cout<<"\nEnter the elements of the array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    k = getMax(A,n);
    radixsort(A,n);
    cout<<"\nThe sorted array is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
    cout<<"\nNumber of elements: "<<n;
    cout<<"\nUpper bound: "<<k;
    cout<<"\n\nEfficiency\n---------\n";
    cout<<"Time Complexity value: "<<tc<<endl;
    cout<<"The Auxillary Space used: "<<10<<endl;
    
    cout<<"\nNote: If C Sort was used on this input, then Auxillary Space would've been "<<k<<endl;
    cout<<"\n\n\n";
    return 0;
    
}
