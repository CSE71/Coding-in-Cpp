
//
//  Coding
//
//  Created by Surya Dheeshjith on 07/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Find the number of combinations of n and x where 0<=x<=n s.th sum of n+x = n^x
long c = 0
while(n){
     c += n%2?0:1;
     n/=2;
}
c=pow(2,c);


//Find number of zeros and 2 power it.
