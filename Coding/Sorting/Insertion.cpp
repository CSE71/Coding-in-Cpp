//
//  main.cpp
//  DAAC++
//
//  Created by Surya Dheeshjith on 01/04/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

#include<iostream>

using namespace std;
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        
        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}  
