//
//  rquick.cpp
//  DAAC++
//
//  Created by Surya Dheeshjith on 01/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include<iostream>
#include<stdlib.h>

using namespace std;



int tc=0;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void random_shuffle(int arr[],int n)
{
    srand(time(NULL));
    int j, temp;
    for (int i = n-1; i > 0; i--)
    {
        j = rand()%(i+1);
        swap(&arr[i],&arr[j]);
        tc++;
    }
    
}




int partion(int arr[], int low, int high)
{
    int pos = low + rand()%(high - low + 1);
    int i = low - 1;
    int j;
    int pivot = arr[pos];
    swap(&arr[pos], &arr[high]);
    for (j = low; j <= high-1; j++)
    {
        tc++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quick_sort(int arr[], int low, int high)
{
    int j;
    if (low < high)
    {
        j = partion(arr, low, high);
        quick_sort(arr, low, j-1);
        quick_sort(arr, j+1, high);
        
    }
}


int main()
{
    
    int arr[50];
    int n;
    cout<<"\nRandomised Quick Sort\n-------------------";
    cout<<"\n\nEnter the size of the array:\n";
    cin>>n;
    cout<<endl<<"Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    random_shuffle(arr,n); //To randomize the array
    quick_sort(arr, 0,n-1);
    
    cout<<"\nThe sorted array is: \n";
    for (int i = 0; i <n i++)
    {
        cout<< arr[i]<<" ";
    }
    
    cout<<"\nNumber of elements: "<<n;
    cout<<"\n\nEfficiency\n---------\n";
    cout<<"Time Complexity Value: "<<tc<<endl;
    cout<<"Algorithm is in-place, so Auxillary Space used is "<<0<<endl;
    cout<<"\n\n\n";
    
    return 0;
    
}
