
//
//  Coding
//
//  Created by Surya Dheeshjith on 07/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Find the number of combinations of n and x where 0<=x<=n s.th sum of n+x = n^x
long c = 0
while(n){
     c += n%2?0:1; // if(n%2==0) return 1; else return 0;
     n/=2;
}
c=pow(2,c);


/*
  The similarity between sum and xor is the same without the consideration of carry.
 So, for the 1 bits in n, there is no choice but to put 0 to avoid carry. But for 0 bits, we can either put 1 or 0. So result is 2^(number of zeros).
 */


