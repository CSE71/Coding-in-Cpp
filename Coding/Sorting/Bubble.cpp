//
//  main.cpp
//  DAAC++
//
//  Created by Surya Dheeshjith on 01/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include<iostream>
#define FULL 30

using namespace std;


int tc=0;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void Bubble_Sort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
                swap(&A[j],&A[j+1]);
            tc++;
        }
    }
    
}


int main()
{
    int n;
    
    cout<<"\nBubble Sort\n------------------";
    cout<<"\nEnter the size of the array :";
    cin>>n;
    /*A stores the elements input by user */
    /*B stores sorted array of elements*/
    int A[FULL];
    
    cout<<"\nEnter the elements of the array:\n";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    Bubble_Sort(A,n);
    cout<<"\nThe sorted array is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<"\nNumber of elements: "<<n;
    cout<<"\n\nEfficiency\n-----------\n";
    cout<<"Time Complexity Value: "<<tc<<endl;
    cout<<"Algorithm is in-place, so Auxillary Space used is "<<0<<endl;
    cout<<"\n\n\n";
    return 0;
}
