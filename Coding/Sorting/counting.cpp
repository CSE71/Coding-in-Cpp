//
//  counting.cpp
//  DAAC++
//
//  Created by Surya Dheeshjith on 01/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include<iostream>

using namespace std;

#define FULL 30



int tc = 0;

void Counting_Sort(int A[],int B[],int n, int k)
{
    int C[FULL];
    
    
    for(int i=0;i<=k;i++)
    {
        /*It will initialize the C with zero*/
        C[i]=0;
        tc++;
    }
    
    for(int j=1;j<=n;j++)
    {
        /*It will count the occurence of every element x in A
         and increment it at position x in C*/
        C[A[j]]++;
        tc++;
    }
    
    for(int i=1;i<=k;i++)
    {
        /*It will store the last
         occurence of the element i */
        C[i]+=C[i-1];
        tc++;
    }
    
    for(int j=n;j>=1;j--)
    {
        /*It will place the elements at their respective index*/
        B[C[A[j]]]=A[j];
        /*It will help if an element occurs more than one time*/
        C[A[j]]=C[A[j]]-1;
        tc++;
    }
    
    
}

int main()
{
    int n;
    int k;
    cout<<"\nCounting Sort\n------------------";
    cout<<"\nEnter the size of the array :";
    cin>>n;
    /*A stores the elements input by user */
    /*B stores sorted array of elements*/
    int A[FULL],B[FULL];
    
    cout<<"\nEnter the elements of the array:\n";
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        if(A[i]>k)
        {
            /*It will modify k if an element
             occurs whose value is greater than k*/
            k=A[i];
        } }
    Counting_Sort(A,B,n,k);
    /*It will print the sorted sequence on the
     console*/
    cout<<"\nThe sorted array is:\n";
    for(int i=1;i<=n;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    cout<<"\nNumber of elements: "<<n;
    cout<<"\nUpper bound: "<<k;
    cout<<"\n\nEfficiency\n---------\n";
    cout<<"Time Complexity Value: "<<tc<<endl;
    cout<<"The Auxillary Space used: "<<n+k<<endl;
    cout<<"\n\n\n";
    return 0;
    
}
