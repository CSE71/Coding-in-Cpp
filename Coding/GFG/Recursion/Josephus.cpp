
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Josephus

// n=5,k=2
/*
 5,2
 4,2
 3,2
 2,2
 1,2 return 1
 2,2 -> (1+1)%2+1 return 1
 3,2 -> (1+1)%3 + 1 return 3
 4,2 -> (3+1)%4 + 1 return 1
 5,2 -> (1+1)%5 + 1 return 3
 
 
 */
// Find the previous winner ((n-1)th winner) and skip k-1 steps
int josephus(int n, int k)
{
    if(n==1)
    return 1;
    
    return (josephus(n-1,k)+k-1)%n+1; // If started from 0 instead, (josephus(n-1,k)+k)%n
}


// Better (Stack overflow will not happen for large inputs)
// Iterative solution for Josephus Problem  
 
  
// Function for finding the winning child. 
long long int find(long long int n, long long int k) 
{ 
    long long int sum = 0, i; 
  
    // For finding out the removed  
    // chairs in each iteration 
    for (i = 2; i <= n; i++) 
        sum = (sum + k) % i; 
  
    return sum + 1; 
} 
  
// Driver function to find the winning child 
int main() 
{ 
    int n = 14, k = 2; 
    find(n, k); 
    return 0; 
} 