
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//First set bit from right

// 5 - 101; -5 - 011
// 5&-5 - 001 

unsigned int getFirstSetBitPos(int n)
{
    return log2(n&-n)+1;
    //doing AND of n and -n as n and -n will have only one bit similar so and will turn all other
    //bits into zero. The result has its log2 taken to find the position and we add 1 to get
    //count from 1 instead of zero
}

