
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// Structure for Min Heap
struct MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
    
    // Constructor for Min Heap
    MinHeap(int c) {
       heap_size = 0;
       capacity = c;
       harr = new int[c];
    }
    
    ~MinHeap()
    {
        delete[] harr;
    }
    
    int parent(int i)
    {
        return (i-1)/2;
    }
    
    int left(int i)
    {
        return (2*i + 1);
    }
    
    int right(int i)
    {
        return (2*i + 2);
    }
    
    void MinHeapify(int ); // Implemented in user editor
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
    
};
/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap=100) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};*/
// You need to write code for below three functions
    
/* Removes min element from min heap and returns it */
int MinHeap ::  extractMin()
{
    // Your code here
    if (heap_size <= 0)
        return -1;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 

    int root = harr[0];
    harr[0] = harr[heap_size-1]; // putting last element at first index
    harr[heap_size-1]=0;
    heap_size--;
    
    MinHeapify(0); // calling Minheapify
    
    return root;
}
/* Removes element from position x in the min heap  */
void MinHeap :: deleteKey(int i)
{
    // Your code here
    if(i<heap_size)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
}
/* Inserts an element at position x into the min heap*/
void MinHeap ::insertKey(int k)
{
   // Your code here
   heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    
    // iterating upto first index till parent is larger than the the child
    while (i != 0 && harr[parent(i)] > harr[i])
    {
      swap(harr[i], harr[parent(i)]);
      i = parent(i);
    }
}
// Decrease Key operation, helps in deleting key from heap
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}
/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
